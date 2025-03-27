/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:09:52 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/27 09:21:52 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	clear_screen(void)
{
	write(STDOUT_FILENO, "\033[H\033[J", 7);
}

void	prompt(void)
{
	char	path[1023];
	char	*user;

	if (getcwd(path, sizeof(path)) == NULL)
		return ;//quit();
	user = getenv("USER");
	ft_printf("%s%s@:%s %s\n%s>\u20BA %s"\
	, GREEN, user, ORANGE, path, BLUE, DEFAULT);
	while (1)
		;
}

int	main(void)
{
	clear_screen();
	prompt();
	return (1);
}
