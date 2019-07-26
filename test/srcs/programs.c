#include "../includes/minishell.h"

int         exec_args(char **av)
{
    int i;
    char s[100];

    i = 0;
    while (av[i])
    {
        if (ft_strcmp(av[i], "exit") == 0)
        {
            free(av[i]);
            return (0);
        }
        if (ft_strcmp(av[i], "cd") == 0)
        {
            ft_printf("%s\n", getcwd(s, 100));
            chdir(av[++i]);
            ft_printf("%s\n", getcwd(s, 100));
            return (1);
        }
        //free(av[i]);
        //system(av[i++]);
    }
    free (av[i]);
    return (1);
}