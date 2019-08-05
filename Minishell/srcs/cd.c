/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:32 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/05 09:31:54 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			error_cd(char *dir)
{
	int			i;

	i = 0;
	ft_putstr("cd: no such file or directory: ");
	while (dir[i])
	{
		if (dir[i] == '\n')
		{
			ft_putchar('\\');
			ft_putchar('n');
		}
		else
			ft_putchar(dir[i]);
		i++;
	}
	free(dir);
	ft_putchar('\n');
}

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

int				old_cd()
{
	char		*old;
	char		*home;
	char		*ret;
	char		cur[4097];
	
	getcwd(cur, 4096);
	old = get_env("OLDPWD=");
	home = get_env("HOME=");
	chdir(old);
	ret = ft_strdup(ft_strstr(old, home) + ft_strlen(home));
	ft_printf("\033[1;34m~%s\033[0m\n", ret);
	setenv_var("OLDPWD", cur);
	free(home);
	free(old);
	free(ret);
	return (0);
}

int				home_cd()
{
	char		*home;
	char		cur[4097];

	getcwd(cur, 4096);
	home = get_env("HOME=");
	chdir(home);
	setenv_var("OLDPWD", cur);
	ft_strdel(&home);
	return (0);
}

int				exec_cd(char *arg)
{
	int			tru;
	char		*ret;
	char		cur[4097];
	char		**dirs;

	tru = 1;
	getcwd(cur, 4096);
	dirs = remove_quotes(arg);
	if (!dirs[1] || (dirs[1][0] == '/' && ft_strlen(dirs[1]) == 1) ||
	(dirs[1][0] == '~' && ft_strlen(dirs[1]) == 1) || (dirs[1][0] == '-' &&
	dirs[1][1] == '-' && ft_strlen(dirs[1]) == 2))
		tru = home_cd();
	else if (ft_strchr(dirs[1], '/'))
		tru = multi_cd(dirs[1]);
	else if (dirs[1][0] == '-' && ft_strlen(dirs[1]) == 1)
		tru = old_cd();
	else
		ret = ft_strdup(dirs[1]);
	if (tru == 1)
	{
		if ((chdir(ret)) == -1)
			error_cd(ret);
		else
		{
			setenv_var("OLDPWD", cur);
			ft_strdel(&ret);
		}
	}
	free_her(dirs);
	return (1);
}
