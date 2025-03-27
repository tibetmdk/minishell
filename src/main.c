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

void    prompt()
{
    char    path[1023];
    char    *user;

    getcwd(path, sizeof(path));
    user = getenv("USER");
    system("clear");
	ft_printf("%s%s@:%s %s\n%s>₺ %s", GREEN, user, ORANGE, path, BLUE, DEFAULT);
    while (1)
        ;
}

int main(void)
{
    prompt();
    return (1);
}