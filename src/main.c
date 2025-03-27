/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:09:52 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/27 14:55:20 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <sys/wait.h>

void	clear_screen(void)
{
	write(STDOUT_FILENO, "\033[H\033[J", 7);
}

void	execute_command(char **args)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror("Fork failed");
	else
		wait(NULL);
}

void	prompt(t_data *data)
{
	char	path[1023];

	if (getcwd(path, sizeof(path)) == NULL)
		return ;
	data->user = getenv("USER");
	while (1)
	{
		ft_printf("%s%s@:%s %s\n%s", GREEN, data->user, ORANGE, path, DEFAULT);
		data->input = readline("\033[38;2;8;99;117m>₺ \033[0m");
		if (!data->input)
			break ;
		add_history(data->input);
		ft_split_args(data);
		if (data->args && data->args[0])
			execute_command(data->args);
	}
}

int	main(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	clear_screen();
	prompt(data);
	return (1);
}
