/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:41:38 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/07/30 09:09:56 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int main(int ac, char **av, char **env)
int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    // read_user_cmd(env);
    read_user_cmd();
    return (0);
}