/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:11:47 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/28 00:17:08 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>

# define GREEN "\033[38;2;175;252;65m"
# define BLUE "\033[38;2;8;99;117m"
# define ORANGE "\033[38;2;255;202;58m"
# define DEFAULT "\033[0m"

typedef struct s_data
{
	char	*input;
	char	*user;
	char	**args;
	int		arg_count;
}				t_data;

//------------- UTILS -------------//
int		ft_printf(const char *str, ...);
int		ft_strlen(char *str);
void	count_words(t_data *data);
char	**ft_split_args(t_data *data);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);

void	prompt(t_data *data);
void	execute_command(char **args);
char	*get_command_path(char *command);
void	clear_screen(t_data *data);

//------------- FREE --------------//
int		free_array(char	**str);

#endif