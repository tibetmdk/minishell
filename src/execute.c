/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 23:26:54 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/28 00:15:53 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	execute_command(char **args)
{
	pid_t	pid;
	char	*cmd_path;

	cmd_path = get_command_path(args[0]);
	if (!cmd_path)
	{
		ft_printf("Command not found: %s\n", args[0]);
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd_path, args, NULL) == -1)
			(perror("execve failed"), free(cmd_path), exit(EXIT_FAILURE));
	}
	else if (pid < 0)
		perror("Fork failed");
	else
		wait(NULL);
	free(cmd_path);
}
