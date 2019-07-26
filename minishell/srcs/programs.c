#include "../includes/minishell.h"

int         exec_args(char **av)
{
    int i;

    i = 0;
    while (av[i])
    {
        if (ft_strcmp(av[i], "exit") == 0)
        {
            free(av[i]);
            return (0);
        }
        free(av[i]);
        system(av[i++]);
    }
    free (av[i]);
    return (1);
}