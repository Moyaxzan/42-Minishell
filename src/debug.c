/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:30:17 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/10/23 15:20:15 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*tta(t_toktype int_type)
{
	if (int_type == 1)
		return ("T_WORD");
	if (int_type == 2)
		return ("T_OPPAR");
	if (int_type == 3)
		return ("T_CLPAR");
	if (int_type == 4)
		return ("T_PIPE");
	if (int_type == 5)
		return ("T_OR");
	if (int_type == 6)
		return ("T_AND");
	if (int_type == 7)
		return ("T_OPCHEV");
	if (int_type == 8)
		return ("T_CLCHEV");
	if (int_type == 9)
		return ("T_DOPCHEV");
	if (int_type == 10)
		return ("T_DCLCHEV");
	return (NULL);
}

void	print_tokens(t_token *tokens)
{
	int	i;

	i = 1;
	printf("TOKENS :\n");
	while (tokens)
	{
		printf("string %d: \"%s\" type : %s\n", i++, tokens->string, tta(tokens->type));
		fflush(stdout);
		tokens = tokens->next;
	}
	printf("\n");
}

void	print_cmd(t_node *node, char *prefix)
{
	int			i;
	t_rdlist	*curr;
	i = -1;
    printf("%s├── Type: CMD\n", prefix);
    printf("%s|   ├── Args: ", prefix);
	while (node->command->arguments[++i])
		printf("%s, ", node->command->arguments[i]);
	curr = node->command->redirects;
    printf("\n%s|   ├── Redir: ", prefix);
	while (curr)
	{
		printf("file : %s, type : %s,\t", curr->file, tta(curr->rdtype));
		curr = curr->next;
	}
	printf("\n");
}

void    pretty_print_ast(t_node *node, char *prefix)
{
	int		len;
	char	*new_prefix;

	if (!node)
		return ;
	if (node->is_command)
		return (print_cmd(node, prefix));
	printf("%s├── Type: %s\n", prefix, tta(node->operand->optype));
	len = strlen(prefix);
	new_prefix = malloc(len + 5);
	strcpy(new_prefix, prefix);
	strcat(new_prefix, node->operand->r_child != NULL ? "|   " : "    ");
	if (node->operand->l_child != NULL)
    {
        printf("%s|   └── Left:\n", prefix);
        pretty_print_ast(node->operand->l_child, new_prefix);
    }
	else
		printf("%s|   └── Left: NULL\n", prefix);
    if (node->operand->r_child != NULL)
    {
        printf("%s└── Right:\n", prefix);
        pretty_print_ast(node->operand->r_child, new_prefix);
    }
    else
        printf("%s└── Right: NULL\n", prefix);
    free(new_prefix);
}