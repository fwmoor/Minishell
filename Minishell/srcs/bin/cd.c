/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:32 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/13 11:05:00 by fremoor          ###   ########.fr       */
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
			return (1);
		}
	setenv_var("OLDPWD", cur);
	free_her(multi);
	return (1);
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
		ret = get_env("OLDPWD=");
		ft_printf("~%s\n", ret);
		free(ret);
	}
	else
		ft_putendl("/");
	setenv_var("OLDPWD", cur);
	free(home);
	free(old);
	return (1);
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
	return (1);
}

int				root_cd(void)
{
	char		cur[4097];

	getcwd(cur, 4096);
	chdir("/");
	setenv_var("OLDPWD", cur);
	return (1);
}

int				exec_cd(char *dir)
{
	int			tru;
	int			test;
	char		*ret;
	char		cur[4097];

	tru = 0;
	test = check_cd(dir);
	getcwd(cur, 4096);
	if (test > 2)
		tru = (test == 3) ? root_cd() : tilda_cd(dir);
	else if (test > 0)
		tru = (test == 1) ? home_cd() : old_cd();
	else if (ft_strchr(dir, '/'))
		tru = multi_cd(dir);
	else
		ret = ft_strdup(dir);
	if (tru == 0)
	{
		if ((chdir(ret)) == -1)
			error_cd(ret);
		else
			setenv_var("OLDPWD", cur);
		ft_strdel(&ret);
	}
	return (1);
}
