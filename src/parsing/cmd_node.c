/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:23:43 by taospa            #+#    #+#             */
/*   Updated: 2023/12/17 12:24:54 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_args(char ***args)
{
	int	i;

	i = -1;
	if (!args || !*args)
		return ;
	while ((*args)[++i])
	{
		free((*args)[i]);
		(*args)[i] = NULL;
	}
	free(*args);
	*args = NULL;
}

t_node	*fill_cmd_node(t_token **token, t_node *res, int *arg_cpt)
{
	t_rdlist	*rd;

	if ((*token)->type == T_WORD)
		res->arguments[(*arg_cpt)++] = ft_strdup((*token)->string);
	else if ((*token)->type > 6 && (*token)->type < 11)
	{
		rd = new_rd(((*token)->type), (*token)->next->string);
		if (!rd)
		{
			free_dchartab(res->arguments);
			free_rdlist(&(res->redirects));
			free(res);
			return (NULL);
		}
		rdlist_add_back(&(res->redirects), rd);
		(*token) = freengonextok((*token));
	}
	(*token) = freengonextok((*token));
	return (res);
}

t_node	*init_cmd_node(t_token **tokens, int malloc_size)
{
	t_node	*res;
	int		arg_cpt;

	arg_cpt = 0;
	res = new_node(1);
	if (!res)
		return (NULL);
	res->arguments = malloc(malloc_size * sizeof(char *));
	if (!res->arguments)
		return (NULL);
	while ((*tokens) && (*tokens)->type != T_PIPE && (*tokens)->type != T_CLPAR
		&& (*tokens)->type != T_OR && (*tokens)->type != T_AND)
		if (!fill_cmd_node(tokens, res, &arg_cpt))
			return (NULL);
	res->arguments[arg_cpt] = NULL;
	return (res);
}

t_node	*handlecommand(t_data *data)
{
	t_token	*curr;
	int		malloc_size;

	curr = data->tokens;
	malloc_size = 0;
	if (curr && curr->type == T_OPPAR)
		return (handlepar(data));
	while (curr && (curr->type < 4 || curr->type > 6) && curr->type != T_CLPAR)
	{
		if (curr->type == T_WORD)
			malloc_size++;
		else if (curr->type > 6 && curr->type < 11)
		{
			// if (!curr->next || curr->next->type != T_WORD)
			// 	return (exit_line(data,
			// 		errnl(2, "syntax error, no file after redirection")), NULL);
			curr = curr->next;
		}
		curr = curr->next;
	}
	return (init_cmd_node(&(data->tokens), ++malloc_size));
}
