/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:09:32 by tmidik            #+#    #+#             */
/*   Updated: 2025/04/11 19:47:51 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec_cd(t_data *data)
{
	char	*path;
	char	cwd[4096];
	
	if (!data->args[1])
	{
		path = getenv("HOME");
		if (!path)
			return (write(2, "cd: HOME not set\n", 17), 0);
	}
	else
		path = data->args[1];
	if (chdir(path) != 0)
		return (write(2, "cd: no such file or directory\n", 30), 0);
	if (getcwd(cwd, sizeof(cwd)))
        setenv("PWD", cwd, 1);
	return (0);
}