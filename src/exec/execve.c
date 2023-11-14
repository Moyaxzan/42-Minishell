/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:20:37 by elrichar          #+#    #+#             */
/*   Updated: 2023/11/07 15:53:24 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_paths(t_data *data)
{
	int	i;

	i = 0;
	while (data->env->envtab[i])
	{
		if (!ft_strncmp(data->env->envtab[i], "PATH=", 5))
			return (&(data->env->envtab[i][5]));
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(t_data *data, char *command)
{
	char	**paths;
	char	*tmp;
	int		i;

	i = 0;
	if (is_path(command))
		return (ft_strdup(command));
	paths = ft_split(get_paths(data), ':');
	if (!paths)
		return (NULL);
	while (paths[i])
	{
		tmp = bettercat(paths[i], command);
		if (!access(tmp, X_OK))
			break ;
		i++;
		free(tmp);
		tmp = NULL;
	}
	free_dchartab(paths);
	return (tmp);
}

int	execute(t_data *data, t_node *node)
{
	char	*cmd_path;
	pid_t	pid;
	pid_t	waitval;
	int		childval;

	childval = 0;
	waitval = 0;
	pid = fork();
	if (pid == -1)
		return (exit_line(data, errnl(-1, "minishell: fork failed")));
	if (!pid)
	{
		cmd_path = get_cmd_path(data, node->command->arguments[0]);
		if (!cmd_path)
			exit(exit_all(data, ferrnl(node->command->arguments[0], NULL,
						"command not found", 127)));
		execve(cmd_path, node->command->arguments, data->env->envtab);
		free(cmd_path);
		exit(exit_line(data, errnl(-1, "minishell: execve failed")));
	}
	waitval = waitpid(pid, &childval, 0);
	if (waitval == -1)
		return (exit_line(data, errnl(-1, "minishell: waitpid failed")));
	return (WEXITSTATUS(childval));
}