/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:36:23 by elrichar          #+#    #+#             */
/*   Updated: 2023/12/08 21:06:05 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	only_red_exec(t_node *node)
{
	if (node->command->redirects->rdtype == 9)
		if (exec_simple_heredoc(node))
			return (1);
	return (0);
}

int	red_and_command_exec(t_node *node, t_data *data)
{
	if (node->command->redirects->rdtype == 9)
		if (exec_heredoc_and_command(node, data))
			return (1);
	return (0);
}

int	handle_redirections(t_data *data, t_node *node)
{
	if (!node->command->redirects && node->command->arguments)
		return (2);
	if (node->command->redirects && !node->command->arguments)
		if (only_red_exec(node))
			return (1);
	if (node->command->redirects && node->command->arguments)
		if (red_and_command_exec(node, data))
			return (1);
	return (0);
}
