/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:36:20 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/12 12:16:07 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int				get_envind(char *key)
{
	int			i;
	char		*temp;
	char		*temp_key;

	i = 0;
	temp_key = (key[0] == '$') ? ft_strdup(key + 1) : ft_strdup(key);
	temp = ft_strjoin(temp_key, "=");
	free(temp_key);
	while (g_env[i])
	{
		if (ft_strncmp(temp, g_env[i], ft_strlen(temp)) == 0)
		{
			ft_strdel(&temp);
			return (i);
		}
		i++;
	}
	ft_strdel(&temp);
	return (-1);
}

char			*setting_var(char *key, char *val)
{
	char		*temp;
	char		*key_temp;
	char		*key_new;

	temp = (key[0] == '$') ? ft_strdup(key + 1) : ft_strdup(key);
	key_temp = ft_strjoin(temp, "=");
	key_new = ft_strjoin(key_temp, val);
	free(key_temp);
	free(temp);
	return (key_new);
}

void			setnew_env(char *key, char *val)
{
	int			i;
	int			len;
	char		*t_key;
	char		**temp;

	i = 0;
	len = 0;
	len = ft_tdlen(g_env) + 1;
	temp = (char **)malloc(sizeof(char *) * (len + 1));
	temp[len] = 0;
	while (g_env[i])
	{
		temp[i] = ft_strdup(g_env[i]);
		i++;
	}
	free_her(g_env);
	t_key = setting_var(key, val);
	temp[i] = ft_strdup(t_key);
	free(t_key);
	g_env = temp;
}

int				setenv_var(char *key, char *val)
{
	int			i;
	char		*temp;

	i = get_envind(key);
	if (i != -1)
	{
		temp = setting_var(key, val);
		free(g_env[i]);
		g_env[i] = ft_strdup(temp);
		ft_strdel(&temp);
	}
	else if (i == -1)
		setnew_env(key, val);
	return (1);
}

int				exec_setenv(char **com)
{
	int			i;

	i = 1;
	if (!(com[1] && com[2]))
		ft_putstr("setenv: too few arguments\n");
	else if (com[3])
		ft_putstr("setenv: too many arguments\n");
	else if (com[1] && com[2])
		i = setenv_var(com[1], com[2]);
	return (i);
}
