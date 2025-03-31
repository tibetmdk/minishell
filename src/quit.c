/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:39:37 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/31 18:21:55 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	quit_shell(t_data *data)
{
	int i;

	if (data->input)
		free(data->input);
	if (data->user)
		free(data->user);
	i = 0;
	while (i < data->arg_count)
	{
		free(data->args[i]);
		i++;
	}
	if (data->args)
		free(data->args);
}

