#include "../includes/minishell.h"

int         exec_args(char **av, char **env)
{
    int i;
    char *home;

    i = 0;
    home = get_env("HOME=", env);
    while (av[i])
    {
        if (ft_strcmp(av[i], "exit") == 0)
        {
            free(av[i]);
            return (0);
        }
        else if (ft_strcmp(av[i], "cd") == 0)
        {
            free(av[i]);
            if (av[++i])
                chdir(av[i]);
            else
            {
                chdir(home);
                //free(home);
            }
            return (1);
        }
        else
        {
            free(av[i]);
            system(av[i++]);
        }
    }
    free (av[i]);
    return (1);
}