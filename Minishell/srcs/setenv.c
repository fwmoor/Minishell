/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:36:20 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/02 16:08:51 by fremoor          ###   ########.fr       */
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
		if (ft_strncmp(temp, g_env[i], ft_strlen(temp)))
		{
			free(temp);
			return (i);
		}
		i++;
	}
	free(temp);
	return (-1);
}

int			setenv_var(char *key, char *val)
{
	int		i;
	char	*temp;
	char	*temp_key;

	i = get_envind(key);
	//if (!(temp = get_env(key, env))
	temp_key = ft_strjoin(key, "=");
	temp = ft_strjoin(temp_key, val);
	free(temp_key);
	free(g_env[i]);
	g_env[i] = ft_strdup(temp);
	return (0);
}

int			exec_setenv(char *arg)
{
	int		i;
	char	**com;

	i = 1;
	com = remove_quotes(arg);
	if (!com[1])
		ft_putstr("setenv: too few arguments\n");
	if (com[1] && com[2] && com[3])
		ft_putstr("setenv: too many arguments\n");
	else
		i = setenv_var(com[1], com[2]);
	free_her(com);
	return (i);
}
