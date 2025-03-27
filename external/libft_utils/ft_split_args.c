/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:46:41 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/27 14:34:49 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	count_words(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	str = data->input;
	data->arg_count = 0;
	while (str[i] != '\0')
	{
		while (str[i] && (str[i] == 32 || str[i] == '\t'))
			i++;
		if (str[i] != '\0')
			data->arg_count++;
		while (str[i] && str[i] != 32 && str[i] != '\t')
			i++;
	}
}

static char	*copy_arg(char *str, int *i)
{
	int		j;
	int		start;
	char	*arg;

	start = *i;
	j = 0;
	while (str[*i] && str[*i] != 32 && str[*i] != '\t')
	{
		(*i)++;
		j++;
	}
	arg = malloc(j + 1);
	if (!arg)
		return (NULL);
	j = 0;
	while (start < *i)
		arg[j++] = str[start++];
	arg[j] = '\0';
	return (arg);
}

char	**ft_split_args(t_data *data)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	count_words(data);
	data->args = malloc(sizeof(char *) * (data->arg_count + 1));
	if (!data->args)
		return (NULL);
	while (data->input[i])
	{
		while (data->input[i] == 32 || data->input[i] == '\t')
			i++;
		if (data->input[i])
		{
			data->args[k] = copy_arg(data->input, &i);
			if (!data->args[k])
				return (NULL);
			k++;
		}
	}
	data->args[k] = NULL;
	return (data->args);
}
