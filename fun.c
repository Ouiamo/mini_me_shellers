/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:50:19 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/08/02 11:24:36 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_sig_handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
    rl_replace_line("", 0);
	rl_redisplay();
}

void    handling_signals(t_signal_status status)
{
    if (status == POS1)
    {
        signal(SIGINT, read_sig_handler);
		signal(SIGQUIT, SIG_IGN);
    }
}

void    cheak_end_of_input(char *input)
{
    if (!input)
    {
        printf("exit\n");
        exit(0);
    }
}

int no_input(char *input)
{
    while (*input)
    {
        if (white_spaces(*input))
            input++;
        else
            break;
    }
    if (!*input)
        return(1);
    return(0);
}

void    read_user_cmd(void)
{
    char    *input;
    char    **arr;
    
    while (1)
    {
        handling_signals(POS1);
        input = readline("minishell $ ");
        cheak_end_of_input(input);
        if (no_input(input))
            continue;
        add_history(input);
        arr = tokensation(input);
        int i = 0;
        while (arr[i] != NULL)
        {
            printf("this is : %s\n ",arr[i]);
            i++;
            printf("%d\n", i);
        }
        syntax_error(arr);
    }
}