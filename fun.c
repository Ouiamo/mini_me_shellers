/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:50:19 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/08/14 09:40:09 by oaoulad-         ###   ########.fr       */
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

void    read_user_cmd(char **env)
{
    char    *input;
    char    **arr;
    t_minishell minishell;
    
    (void)env;
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
        // while (arr[i] != NULL)
        // {
        //     printf("this is : %s\n ",arr[i]);
        //     i++;
        //     printf("%d\n", i);
        // }
        if (syntax_error(arr))
            continue;
        parsing(&minishell, arr);
        i = 0;
		while (i < nbr_commands(arr))
		{
			printf("this is command %s\n", minishell.shell[i].full_commnad);
			printf("this is cmd %s\n", minishell.shell[i].cmd);
			printf("this is pipetype %d\n", minishell.shell[i].pipe_type);
			printf("this is parant %d\n", minishell.shell[i].prnt);
			while (minishell.shell[i].flags)
			{
			printf("this is args %s\n", (char *)minishell.shell[i].flags->content);
			minishell.shell[i].flags = minishell.shell[i].flags->next;
			}
			printf ("---------------------this is the nbr %d-------------------\n", i);
			i++;
		}
    }
}