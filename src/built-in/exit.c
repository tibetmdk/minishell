/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:14:17 by tmidik            #+#    #+#             */
/*   Updated: 2025/04/07 17:00:37 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec_exit(t_data *data)
{
	long	exit_code;
	char	*arg;
	int		i;

	i = 0;
	exit_code = 0;
	if (data->args[1])
	{
		arg = data->args[1];
		while (arg[i])
		{
			if ((arg[i] < '0' || arg[i] > '9') && !(i == 0 && (arg[i] == '+' \
				|| arg[i] == '-')))
				(write(2, "minishell: exit: numeric argument required\n", \
				43), exit(255));
			i++;
		}
		exit_code = ft_atol(arg);
		if (data->args[2])
		{
			write(2, "exit:too many arguments\n", 25);
			return (1);
		}
	}
	return (exit(exit_code % 256), 0);
}
