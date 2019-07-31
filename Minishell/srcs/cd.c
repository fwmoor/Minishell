/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:32 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/31 14:08:25 by fremoor          ###   ########.fr       */
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
	{
	}
	free_her(multi);
	return (0);
}

int				old_cd(char **env)
{
	char		*old;

	old = get_env("OLDPWD=", env);
	chdir(old);
	free(old);
	return (0);
}

int				home_cd(char **env)
{
	char		*home;

	home = get_env("HOME=", env);
	chdir(home);
	free(home);
	return (0);
}

int				exec_cd(char *arg, char **env)
{
	int			tru;
	char		*ret;
	char		**dirs;

	tru = 1;
	dirs = remove_quotes(arg);
	if (!dirs[1] || (dirs[1][0] == '/' && ft_strlen(dirs[1]) == 1) ||
	(dirs[1][0] == '~' && ft_strlen(dirs[1]) == 1) || (dirs[1][0] == '-' &&
	dirs[1][1] == '-' && ft_strlen(dirs[1]) == 2))
		tru = home_cd(env);
	else if (ft_strchr(dirs[1], '/'))
		tru = multi_cd(dirs[1]);
	else if (dirs[1][0] == '-' && ft_strlen(dirs[1]) == 1)
		tru = old_cd(env);
	else
		ret = ft_strdup(dirs[1]);
	free_her(dirs);
	if (tru == 1)
	{
		chdir(ret);
		free(ret);
	}
	return (1);
}
