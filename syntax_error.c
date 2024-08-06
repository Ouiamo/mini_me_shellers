#include "minishell.h"

char    *cheak_prnt(char **arr)
{
    int prnt;

    prnt = 0;
    while (*arr)
    {
        if (**arr == '(')
            prnt++;
        else if (**arr == ')')
            prnt--;
        if (prnt < 0)
            return (")");
        arr++;
    }
    if (prnt > 0)
            return ("(");
    return (0);
}

char    *first_cheak(char **arr)
{
    if (arr[0][1] && arr[0][2])
        return (*arr);
    arr++;
    if (!*arr)
        return ("newline");
    else if (*arr && (**arr == '|' || **arr == '&' || **arr == '<' || **arr == '>' || **arr == '(' || **arr == ')'))
        return (*arr);
    return (NULL);
}

char    *second_cheak(char **arr)
{
    if (arr[0][0] == '&' && !(arr[0][1]))
		return (*arr);
    if (arr[0][1] && arr[0][2])
        return (*arr);
    arr++;
    if (!*arr)
        return ("newline");
    else if (*arr && (**arr == '|' || **arr == '&' || **arr == ')'))
        return (*arr);
    return (NULL);

}

char    *third_cheak(char **arr)
{
    // printf("%s\n", *arr);
    arr++;
    if (!*arr)
        return ("newline");
    else if (*arr && (**arr == '|' || **arr == '&'))
        return (*arr);
    // printf("%s\n", *arr);
    return (NULL);
}

char    *cheak_arr(char  **arr)
{
    char    *ptr;

    if (**arr == '|' || **arr == '&')
        return (*arr);
    if (cheak_prnt(arr))
        return (cheak_prnt(arr));
    while (*arr)
    {
        ptr = first_cheak(arr);
        if ((**arr == '>' || **arr == '<') && ptr)
            return (ptr);
        ptr = second_cheak(arr);
        if ((**arr == '|' || **arr == '&') && ptr)
            return (ptr);
        ptr = third_cheak(arr);
        if (**arr == '(' && ptr)
            return (ptr);
        if (*arr)
            arr++;  
    }
    return (NULL);
}

void    syntax_error(char **arr)
{
    if (cheak_arr(arr))
    {
        printf("minishell: syntax error near unexpected token `%s'\n", cheak_arr(arr));
    }
}

// int main (int ac, char **av)
// {
//     if (ac > 1)
//     printf("%s\n", cheak_arr(av));
// }