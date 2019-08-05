/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:36:20 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/05 16:42:17 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				exec_env(void)
{
	int			i;

	i = 0;
	while (g_env[i])
		ft_putendl(g_env[i++]);
	return (1);
}

int				get_envind(char *key)
{
	int			i;
	char		*temp;

	i = 0;
	temp = ft_strjoin(key, "=");
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

void			setnew_env(char *key, char *val)
{
	int			i;
	int			len;
	char		*key_temp;
	char		*key_new;
	char		**temp;

	i = 0;
	len = 0;
	while (g_env[len])
		len++;
	len++;
	temp = (char **)malloc(sizeof(char *) * (len + 1));
	temp[len] = 0;
	while (g_env[i])
	{
		temp[i] = ft_strdup(g_env[i]);
		i++;
	}
	free_her(g_env);
	key_temp = ft_strjoin(key, "=");
	key_new = ft_strjoin(key_temp, val);
	temp[i] = ft_strdup(key_new);
	free(key_temp);
	free(key_new);
	g_env = temp;
}

int				setenv_var(char *key, char *val, int ow)
{
	int			i;
	char		*temp;
	char		*temp_key;

	i = get_envind(key);
	if (i != -1 && ow > 0)
	{
		temp_key = ft_strjoin(key, "=");
		temp = ft_strjoin(temp_key, val);
		ft_strdel(&temp_key);
		ft_strdel(&g_env[i]);
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
	int			ow;

	i = 1;
	ow = 0;
	if (!(com[1] && com[2] && com[3]))
		ft_putstr("setenv: too few arguments\n");
	else if (com[1] && com[2] && com[3] && com[4])
		ft_putstr("setenv: too many arguments\n");
	else if (com[1] && com[2] && com[3])
	{
		ow = ft_atoi(com[3]);
		i = setenv_var(com[1], com[2], ow);
	}
	return (i);
}
