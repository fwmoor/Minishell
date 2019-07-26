#include "../includes/minishell.h"

char		*get_env(char *str, char **env)
{
    int		i;
	char	*temp;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(str, env[i], ft_strlen(str)) == 0)
			temp = ft_strdup(env[i]);
		i++;
	}
	return (temp);
}