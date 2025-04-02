/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 23:26:54 by tmidik            #+#    #+#             */
/*   Updated: 2025/04/01 12:33:20 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_built_in(t_data *data)
{
	(void)data;
	if (ft_strcmp(data->args[0], "echo") == 0)
		exec_echo(data);
	/*
	else if (ft_strcmp(data->args[0], "cd") == 0)
		exec_cd(data);
	else if (ft_strcmp(data->args[0], "pwd") == 0)
		exec_pwd(data);
	else if (ft_strcmp(data->args[0], "export") == 0)
		exec_export(data);
	else if (ft_strcmp(data->args[0], "unset") == 0)
		exec_unset(data);
	else if (ft_strcmp(data->args[0], "env") == 0)
		exec_env(data);
	else if (ft_strcmp(data->args[0], "exit") == 0)
		exec_exit(data);
	else
		return (-1);*/
	return (1);
}

void	execute_command(t_data *data)
{
	pid_t	pid;
	char	*cmd_path;

	if (is_built_in(data))
		return ;
	cmd_path = get_command_path(data->args[0]);
	if (!cmd_path)
	{
		ft_printf("Command not found: %s\n", data->args[0]);
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd_path, data->args, NULL) == -1)
			(perror("execve failed"), free(cmd_path), exit(EXIT_FAILURE));
	}
	else if (pid < 0)
		perror("Fork failed");
	else
		wait(NULL);
	free(cmd_path);
}
