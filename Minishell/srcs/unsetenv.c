/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 11:56:08 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/05 14:22:22 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			unsetenv_var(char *key)
{
	int		i;
	int		j;
	int		len;
	int		key_ind;
	char	**temp;

	i = 0;
	j = 0;
	len = 0;
	if ((key_ind = get_envind(key)) == -1)
		return (0);
	while (g_env[len])
		len++;
	temp = (char **)malloc(sizeof(char *) * (len + 1));
	temp[len] = 0;
	if (temp)
	{
		while (i < len && g_env[i])
		{
			if (i != key_ind)
				temp[j++] = ft_strdup(g_env[i]);
			i++;
		}
		free_her(g_env);
		g_env = temp;
	}
	return (1);
}

int			exec_unsetenv(char *arg)
{
	int		i;
	char	**com;

	i = 1;
	com = remove_quotes(arg);
	if (!(com[1]))
		ft_putstr("setenv: too few arguments\n");
	else if (com[1] && com[2])
		ft_putstr("setenv: too many arguments\n");
	else if (com[1])
		i = unsetenv_var(com[1]);
	free_her(com);
	return (i);
}
