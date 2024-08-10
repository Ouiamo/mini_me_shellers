#include "minishell.h"

int nbr_commands(char **arr)
{
    int i;

    i = 1;
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
    shell = malloc(sizeof(t_shell) * (i + 1));
    
    while (i > -1)
    {
        shell[i].pipe_type = 0;
        shell[i].prnt = 0;
        shell[i].cmd = NULL;
        shell[i].flags = NULL;
        i--;
    }
}

//----------------------------------------------------------------------------------------

t_shell add_pipetype(char   *arr, t_shell shell)
{
    if (arr[0] == '&' && arr[1])
        shell.pipe_type = 3;
    if (arr[0] == '|' && arr[1])
        shell.pipe_type = 2;
    else
        shell.pipe_type = 1;
    return (shell);
}

t_shell add_prnt(char c, t_shell shell)
{
    if (c == '(')
        shell.prnt++;
    else if (c == ')')
        shell.prnt--;
    return (shell);
}

t_list  *add_flags(char *arr, t_shell shell)
{
    t_list  *new_flag;
    t_list  *tmp;

    new_flag = malloc(sizeof(t_list));
    new_flag->content = arr;
    new_flag->next = NULL;
    if (!shell.flags)
        return (new_flag);
    tmp = shell.flags;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new_flag;
    return(shell.flags);
}

t_shell add_cmd(char ***arr, t_shell shell)
{
    while (**arr)
    {
        if (***arr == '|' || ***arr == '&' || ***arr == '(' || ***arr == ')' || ***arr == '<' || ***arr == '>')
            break;
        if (!shell.cmd)
            shell.cmd = **arr;
        else
            shell.flags = add_flags(**arr, shell);
        (*arr)++;
    }
    (*arr)--;
    return (shell);
}

void    creat_my_shell(t_shell *shell, char  **arr)
{
    int i;

    i = 0;
    while (*arr)
    {
        if (**arr == '|' || *arr == '&&')
        {
            shell[i] = add_pipetype(*arr, shell[i]);
            i++;
        }
        else if (**arr == '(' || **arr == ')')
            shell[i] = add_prnt(**arr, shell[i]);
        else
            shell[i] = add_cmd(&arr, shell[i]);
        arr++;
    }
    
}
//---------------------------------------------------------------------------------------------------

void    parsiing(char **env, t_shell    *shell, char **arr)
{
    initial_my_shell(shell, arr);
    creat_my_shell(shell, arr);
}