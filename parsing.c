#include "minishell.h"

int nbr_commands(char **arr)
{
    int i;

    i = 0;
    while (*arr)
    {
        if (**arr == '|' || **arr == '&')
            i++;
        arr++;
    }
    return (i);
}
void    initial_my_shell(t_shell *shell, char  **arr)
{
    int i ;

    i = nbr_commands(arr);
    while (i > -1)
    {
        shell[i].pipe_type = 0;
        shell[i].prnt = 0;
        shell[i].cmd = NULL;
        shell[i].args = NULL;
        i--;
    }
}

void    creat_my_shell(t_shell *shell, char  **arr)
{
    
}

void    parsiing(char **env, t_shell    *shell, char **arr)
{
    initial_my_shell(shell, arr);
    creat_my_shell(shell, arr);
}