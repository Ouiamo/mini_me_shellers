/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:42:23 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/08/10 18:33:27 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_shell
{
	char	*full_commnad;
	char	*cmd;
	int		pipe_type;
	int		prnt;
	t_list	*flags;
	char	**arr;
}								t_shell;

typedef enum e_signal_status
{
	POS1,
	DEFAULT,
	IGNORE,
}		t_signal_status;

//libft funtions:

char	*ft_strdup(const char *s1);
char	*ft_substr(char *s, int start, size_t len);
size_t  ft_strlen(char *str);

//minishell functions:

// void    read_user_cmd(char **env);
int white_spaces(char c);
void    read_user_cmd(char **env);
char **tokensation(char *input);
void    syntax_error(char **arr);
void    parsing(t_shell    *shell, char **arr);


#endif
//cc -Wall -Wextra -Werror fun.c main.c tokenisation.c syntax_error.c libft1.c parsing.c  -lreadline
