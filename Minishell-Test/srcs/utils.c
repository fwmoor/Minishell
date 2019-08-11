/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:12:13 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/11 15:44:46 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			pop_env(char **env)
{
	int			i;

	i = 0;
	while (env[i])
		i++;
	g_env = (char **)malloc(sizeof(char *) * (i + 1));
	if (g_env)
	{
		g_env[i--] = NULL;
		while (i >= 0)
		{
			g_env[i] = ft_strdup(env[i]);
			i--;
		}
	}
}

char			**remove_quotes(char *str)
{
	int			i;
	char		**ret;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"')
				i++;
		}
		if (str[i] == ' ' || str[i] == '\t')
			str[i] = '"';
		i++;
	}
	ret = ft_strsplit(str, '"');
	return (ret);
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

char			*get_env(char *str)
{
	int			i;

	i = 0;
	while (g_env[i])
	{
		if (ft_strncmp(str, g_env[i], ft_strlen(str)) == 0)
			return (ft_strdup(ft_strchr(g_env[i], '=') + 1));
		i++;
	}
	return (NULL);
}

void			get_dir_path(void)
{
	char		*home;
	char		buf[4097];

	getcwd(buf, 4096);
	check_colour(con_arr[0]);
	if (ft_strequ(con_arr[3], "True"))
	{
		if (ft_strcmp(buf, "/"))
		{
			home = get_env("HOME=");
			ft_printf("%C  ", (ft_strequ(home, buf) ? 0xf015 : 0xf07b));
			setenv_var("PWD", buf);
			ft_printf("~%s", ft_strstr(buf, home) + ft_strlen(home));
			free(home);
		}
		else
			ft_printf("%C  /", 0xf1bb);
		check_nl(con_arr[2]);
	}
	ft_putstr("$>");
	ft_putstr(C_DEF);
}
