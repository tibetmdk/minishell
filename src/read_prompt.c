/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 23:25:45 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/31 18:55:00 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
			execute_command(data);
	}
}

char	*get_command_path(char *command)
{
	char	*path;
	char	**paths;
	char	*full_path;
	int		i;

	if (access(command, X_OK) == 0)
		return (ft_strdup(command));
	path = getenv("PATH");
	if (!path)
		return (NULL);
	paths = ft_split(path, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = malloc(ft_strlen(paths[i]) + ft_strlen(command) + 2);
		if (!full_path)
			return (NULL);
		sprintf(full_path, "%s/%s", paths[i], command);
		if (access(full_path, X_OK) == 0)
			return (free_array(paths), full_path);
		free(full_path);
		i++;
	}
	return (free_array(paths), NULL);
}
