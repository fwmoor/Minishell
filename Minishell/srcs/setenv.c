/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:36:20 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/05 10:20:41 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			get_envind(char *key)
{
	int		i;
	char	*temp;

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

int			setenv_var(char *key, char *val, int ow)
{
	int		i;
	char	*temp;
	char	*temp_key;

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
	return (1);
}

int			exec_setenv(char *arg)
{
	int		i;
	int		ow;
	char	**com;

	i = 1;
	ow = 0;
	com = remove_quotes(arg);
	if (!(com[1] && com[2] && com[3]))
		ft_putstr("setenv: too few arguments\n");
	else if (com[1] && com[2] && com[3] && com[4])
		ft_putstr("setenv: too many arguments\n");
	else if (com[1] && com[2] && com[3])
	{
		ow = ft_atoi(com[3]);
		i = setenv_var(com[1], com[2], ow);
	}
	free_her(com);
	return (i);
}
