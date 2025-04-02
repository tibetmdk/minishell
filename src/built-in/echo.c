/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:11:49 by beldemir          #+#    #+#             */
/*   Updated: 2025/04/02 10:46:24 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec_echo(t_data *data)
{
	int	flag_n;
	int	i;
	int	j;

	flag_n = 0;
	i = 1;
	while (i < data->arg_count && data->args[i][0] == '-')
	{
		j = 1;
		while (data->args[i][j] == 'n')
			j++;
		if (data->args[i][j] != 'n' && data->args[i][j] != '\0')
			break ;
		i++;
		flag_n = 1;
	}
	while (i < data->arg_count)
	{
		ft_printf("%s", data->args[i]);
		if (++i < data->arg_count)
			write(STDOUT_FILENO, " ", 1);
	}
	if (flag_n == 0)
		ft_printf("\n");
	return (0);
}
