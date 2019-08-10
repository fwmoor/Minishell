/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:32 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/10 09:25:54 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int				multi_cd(char *dirs)
{
	int			i;
	char		cur[4097];
	char		**multi;

	i = 0;
	getcwd(cur, 4096);
	multi = ft_strsplit(dirs, '/');
	while (multi[i])
		if ((chdir(multi[i++])) == -1)
		{
			ft_printf("cd: no such file or directory: %s\n", dirs);
			free_her(multi);
			chdir(cur);
			return (0);
		}
	setenv_var("OLDPWD", cur);
	free_her(multi);
	return (0);
}

int				old_cd(void)
{
	char		*old;
	char		*home;
	char		*ret;
	char		cur[4097];

	getcwd(cur, 4096);
	old = get_env("OLDPWD=");
	home = get_env("HOME=");
	chdir(old);
	if (!ft_strequ(old, "/"))
	{
		ret = ft_strdup(ft_strstr(old, home) + ft_strlen(home));
		ft_printf("~%s\n", ret);
		free(ret);
	}
	else
		ft_putendl("/");
	setenv_var("OLDPWD", cur);
	free(home);
	free(old);
	return (0);
}

int				home_cd(void)
{
	char		*home;
	char		cur[4097];

	getcwd(cur, 4096);
	home = get_env("HOME=");
	chdir(home);
	ft_strdel(&home);
	setenv_var("OLDPWD", cur);
	return (0);
}

int				root_cd(void)
{
	char		cur[4097];

	getcwd(cur, 4096);
	chdir("/");
	setenv_var("OLDPWD", cur);
	return (0);
}

int				exec_cd(char **dirs)
{
	int			tru;
	int			test;
	char		*ret;
	char		cur[4097];

	tru = 1;
	test = check_cd(dirs[1]);
	getcwd(cur, 4096);
	if (test > 2)
		tru = (test == 3) ? root_cd() : tilda_cd(dirs[1]);
	else if (test > 0)
		tru = (test == 1) ? home_cd() : old_cd();
	else if (ft_strchr(dirs[1], '/'))
		tru = multi_cd(dirs[1]);
	else
		ret = ft_strdup(dirs[1]);
	if (tru == 1)
	{
		if ((chdir(ret)) == -1)
			error_cd(ret);
		else
			setenv_var("OLDPWD", cur);
		ft_strdel(&ret);
	}
	return (1);
}
