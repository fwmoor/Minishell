/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:32 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/30 10:33:49 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				multi_cd(char *dirs)
{
	int			i;
	char		**multi;

	i = 0;
	multi = ft_strsplit(dirs, '/');
	while (multi[i])
		chdir(multi[i++]);
	free_her(multi);
	return (0);
}

int				exec_cd(char *arg, char **env)
{
	int			tru;
	char		*ret;
	char		*home;
	char		**dirs;

	tru = 1;
	dirs = ft_strsplit(arg, ' ');
	if (dirs[1] == NULL || (dirs[1][0] == '/' && ft_strlen(dirs[1]) == 1))
	{
		home = get_env("HOME=", env);
		ret = ft_strdup(home);
		free(home);
	}
	else if (ft_strchr(dirs[1], '/'))
		tru = multi_cd(dirs[1]);
	else
		ret = ft_strdup(dirs[1]);
	free_her(dirs);
	if (tru == 1)
	{
		chdir(ret);
		free(ret);
	}
	free(arg);
	return (1);
}
