/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:32 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/05 15:32:40 by fremoor          ###   ########.fr       */
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
	setenv_var("OLDPWD", cur, 1);
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
	ret = ft_strdup(ft_strstr(old, home) + ft_strlen(home));
	ft_printf("\033[1;34m~%s\033[0m\n", ret);
	setenv_var("OLDPWD", cur, 1);
	free(home);
	free(old);
	free(ret);
	return (0);
}

int				home_cd(void)
{
	char		*home;
	char		cur[4097];

	getcwd(cur, 4096);
	home = get_env("HOME=");
	chdir(home);
	setenv_var("OLDPWD", cur, 1);
	ft_strdel(&home);
	return (0);
}

int				exec_cd(char **dirs)
{
	for (int j = 0; dirs[j]; j++)
		ft_putendl(dirs[j]);
	// int			tru;
	// char		*ret;
	// char		cur[4097];

	// tru = 1;
	// getcwd(cur, 4096);
	// if (check_cd(dirs[1]) > 0)
	// 	tru = (check_cd(dirs[1]) == 1) ? old_cd() : home_cd();
	// else if (ft_strchr(dirs[1], '/'))
	// 	tru = multi_cd(dirs[1]);
	// else
	// 	ret = ft_strdup(dirs[1]);
	// if (tru == 1)
	// {
	// 	if ((chdir(ret)) == -1)
	// 		error_cd(ret);
	// 	else
	// 		setenv_var("OLDPWD", cur, 1);
	// 	ft_strdel(&ret);
	// }
	// free_her(dirs);
	return (1);
}
