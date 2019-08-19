/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 11:56:08 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/19 09:58:36 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int				exec_env(void)
{
	int			i;

	i = 0;
	while (g_env[i])
	{
		ft_putendl(g_env[i]);
		i++;
	}
	return (1);
}

int				start_with(char *check, char *val)
{
	int			i;
	int			len;

	i = 0;
	len = ft_strlen(val);
	while (i < len)
	{
		if (check[i] != val[i])
			return (0);
		i++;
	}
	return (1);
}

int				unsetenv_var(char *key)
{
	int		i;
	int		j;
	int		len;
	char	*key_temp;
	char	**new_env;

	i = 0;
	j = 0;
	len = ft_tdlen(g_env);
	key_temp = ft_strjoin(key, "=");
	new_env = (char **)malloc(sizeof(char *) * (--len + 1));
	new_env[len] = 0;
	while (i < len && g_env[j])
	{
		if (!start_with(g_env[j], key_temp))
		{
			new_env[i] = ft_strdup(g_env[j]);
			i++;
		}
		j++;
	}
	free(key_temp);
	free_her(g_env);
	g_env = new_env;
	return (1);
}

int				exec_unsetenv(char **com)
{
	int			i;
	int			key_ind;

	i = 1;
	if (!(com[1]))
		ft_putstr("unsetenv: too few arguments\n");
	else if (com[1] && com[2])
		ft_putstr("unsetenv: too many arguments\n");
	else if (com[1])
	{
		if ((key_ind = get_envind(com[1])) != -1)
			i = unsetenv_var(com[1]);
		else
			ft_printf("unsetenv: %s: variable not found\n", com[1]);
	}
	return (i);
}
