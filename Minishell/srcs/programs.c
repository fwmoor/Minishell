#include "../includes/minishell.h"

int         exec_args(char **av, char **env)
{
    int		i;
    char	*home;
    char	*temp;

    i = 0;
    temp = get_env("HOME=", env);
    home = ft_strchr(temp, '=') + 1;
    while (av[i])
    {
        if (ft_strcmp(av[i], "exit") == 0)
        {
            free(av[i]);
            return (0);
        }
        if (ft_strncmp(av[i], "cd", 2) == 0)
        {
            free(av[i++]);
            if (!(av[i]))
                exec_cd(home);
            else
            {
                exec_cd(av[i]);
                free(av[i++]);
            }
        }
        else
        {
            free(av[i]);
            system(av[i++]);
        }
    }
    free (av[i]);
    free (temp);
    return (1);
}