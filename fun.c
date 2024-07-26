/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:50:19 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/07/26 10:47:28 by oaoulad-         ###   ########.fr       */
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

void    cheak_empty_input(char *input)
{
    if (!input)
    {
        printf("\nexit\n");
        exit(0);
    }
}

void    read_user_cmd(t_shell *shell)
{
    char    *input;
    int     status;
    char    **tab;
    
    while (1)
    {
        handling_signals(POS1);
        input = readline("minishell $ ");
        cheak_empty_input(input);
        add_history(input);
        tab = tokensation(input);
        int i = 0;
        while (tab[i] != NULL)
        {
            printf("this is : %s\n ",tab[i]);
            i++;
            printf("%d\n", i);
        }
    }
}