/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:32 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/20 15:51:19 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int				old_cd(void)
{
	char		*old;
	char		*home;
	char		*ret;
	char		cur[4097];

	getcwd(cur, 4096);
	old = get_env("OLDPWD=");
	if (get_envind("OLDPWD") == -1)
		return (error_cd(""));
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

int				tilda_error(char *dir, int err, char *cur, char *home)
{
	char		*temp;

	if (dir[0] == '~')
		dir++;
	if (err == 1)
		ft_printf("minishell: no such user or named directory: %s\n", dir);
	else if (err == 2)
	{
		temp = ft_strjoin(home, dir);
		ft_printf("minishell: no such file or directory: %s\n", temp);
		free(temp);
	}
	chdir(cur);
	free(home);
	return (1);
}

int				tilda_cd(char *dirs)
{
	int			i;
	int			err;
	char		cur[4097];
	char		*home;
	char		**multi;

	i = 1;
	err = 0;
	getcwd(cur, 4096);
	home = get_env("HOME=");
	chdir(home);
	multi = ft_strsplit(dirs, '/');
	if (!multi[1] && ft_strlen(dirs) > 1)
		err = tilda_error(dirs, 1, cur, home);
	else
		while (multi[i] && err == 0)
			if ((chdir(multi[i++])) == -1)
				err = tilda_error(dirs, 2, cur, home);
	if (err == 0)
	{
		setenv_var("OLDPWD", cur);
		free(home);
	}
	free_her(multi);
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
	if (test == 3)
		tru = tilda_cd(dir);
	else if (test > 0)
		tru = (test == 1) ? home_cd() : old_cd();
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
