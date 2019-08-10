/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:35:03 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/10 09:27:06 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				check_cd(char *dir)
{
	if (!dir)
		return (1);
	else if (dir[0] == '~')
		return (4);
	else if (dir[0] == '-' && dir[1] == '-' && ft_strlen(dir) == 2)
		return (1);
	else if (dir[0] == '-' && ft_strlen(dir) == 1)
		return (2);
	else if (dir[0] == '/' && ft_strlen(dir) == 1)
		return (3);
	return (0);
}

void			check_colour(char *str)
{
	if (ft_strequ(str, "Blue"))
		ft_putstr(C_BLUE);
	else if (ft_strequ(str, "Green"))
		ft_putstr(C_GREEN);
	else if (ft_strequ(str, "Red"))
		ft_putstr(C_RED);
	else if (ft_strequ(str, "Yellow"))
		ft_putstr(C_YELLOW);
	else if (ft_strequ(str, "Cyan"))
		ft_putstr(C_CYAN);
	else if (ft_strequ(str, "Magenta"))
		ft_putstr(C_MAGENTA);
	else
		ft_putstr(C_DEF);
}

void			check_nl(char *str)
{
	if (ft_strequ(str, "True"))
		ft_putchar('\n');
}

int				tilda_cd(char *dirs)
{
	int			i;
	char		cur[4097];
	char		*home;
	char		**multi;

	i = 1;
	getcwd(cur, 4096);
	home = get_env("HOME=");
	chdir(home);
	free(home);
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
