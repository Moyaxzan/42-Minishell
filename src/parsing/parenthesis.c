/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:04:21 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/12/15 11:16:51 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// TODO : protect handlecommand return value in case of malloc fail
t_node	*handlepar(t_data *data)
{
	if (!data->tokens && data->tokens->type != T_OPPAR)
		return (NULL);
	data->tokens = freengonextok(data->tokens);
	data->tmp_tree = NULL;
	while (data->tokens && data->tokens->type != T_CLPAR)
	{
		if (data->tokens->type == T_WORD || data->tokens->type == T_OPPAR)
			add_nodeontop(handlecommand(data), &(data->tmp_tree));
		else if (data->tokens->type > 4 && data->tokens->type < 7)
			add_nodeontop(handleoperator(data), &(data->tmp_tree));
		else if (data->tokens->type == T_PIPE)
			handlepipe(data);
	}
	if (data->tokens->type == T_CLPAR)
		data->tokens = freengonextok(data->tokens);
	if (data->tmp_tree)
		data->tmp_tree->subshell = 1;
	return (data->tmp_tree);
}
