/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:42:23 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/07/26 09:49:22 by oaoulad-         ###   ########.fr       */
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


typedef struct s_shell
{
	
	char	**arr;
}								t_shell;

typedef enum e_signal_status
{
	DEFAULT,
	POS1,
	IGNORE,
}		t_signal_status;

//libft funtions:

char	*ft_strdup(const char *s1);
char	*ft_substr(char *s, int start, size_t len);

//minishell functions:

void    read_user_cmd(t_shell *shell);
char **tokensation(char *input);

#endif