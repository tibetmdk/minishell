/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 23:28:36 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/28 00:17:22 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static	int	count_word(const char *str, char sep)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != sep && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*str == sep)
			in_word = 0;
		str++;
	}
	return (count);
}

static	char	*get_next_word(char **s, char c)
{
	char	*start;
	size_t	word_len;

	while (**s == c && **s != '\0')
		(*s)++;
	start = *s;
	while (**s != c && **s != '\0')
		(*s)++;
	word_len = *s - start;
	return (ft_substr(start, 0, word_len));
}

static	void	free_words(char **words, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	**ft_split(char *s, char c)
{
	char	**words;
	size_t	words_count;
	size_t	i;

	if (!s)
		return (NULL);
	words_count = count_word(s, c);
	words = (char **)malloc((words_count + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	while (i < words_count)
	{
		words[i] = get_next_word(&s, c);
		if (!words[i])
		{
			free_words(words, i);
			return (NULL);
		}
		i++;
	}
	words[i] = NULL;
	return (words);
}
