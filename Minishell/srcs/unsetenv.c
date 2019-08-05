/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 11:56:08 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/05 15:20:04 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			unsetenv_var(int key_ind)
{
	int		i;
	int		j;
	int		len;
	char	**temp;

	i = 0;
	j = 0;
	len = 0;
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

int			exec_unsetenv(char **com)
{
	int		i;
	int		key_ind;

	i = 1;
	if (!(com[1]))
		ft_putstr("unsetenv: too few arguments\n");
	else if (com[1] && com[2])
		ft_putstr("unsetenv: too many arguments\n");
	else if (com[1])
		if ((key_ind = get_envind(com[1])) != -1)
			i = unsetenv_var(key_ind);
	free_her(com);
	return (i);
}
