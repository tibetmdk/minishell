/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:09:52 by tmidik            #+#    #+#             */
/*   Updated: 2025/04/02 11:09:05 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	clear_screen(t_data *data)
{
	write(STDOUT_FILENO, "\033[H\033[J", 7);
	prompt(data);
}

int	main(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (perror("Malloc failed."), 1);
	clear_screen(data);
	quit_shell(data);
}
