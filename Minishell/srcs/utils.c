/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:12:13 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/13 10:32:15 by fremoor          ###   ########.fr       */
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
	zsh_level();
}

char			*remove_quotes(char *str)
{
	int			i;
	int			i1;
	int			len = 0;
	char		c;
	char		*ret;

	i = quote(str, '\'');
	i1 = quote(str, '"');
	if (i != -1 && i1 != -1)
		c = (i < i1) ? '\'' : '"';
	else if (i == -1 || i1 == -1)
		c = (i == -1) ? '"' : '\'';
	i = 0;
	i1 = 0;
	while (str[i])
		if (str[i++] != c)
			len++;
	ret = ft_strnew(len);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
			ret[i1++] = str[i++];
	}
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
	return (1);
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
	check_colour(g_arr[0]);
	if (ft_strequ(g_arr[3], "True"))
	{
		if (ft_strcmp(buf, "/"))
		{
			home = get_env("HOME=");
			setenv_var("PWD", buf);
			ft_printf("%C ", (ft_strequ(home, buf) ? 0xf015 : 0xf07b));
			ft_printf("~%s", ft_strstr(buf, home) + ft_strlen(home));
			free(home);
		}
		else
			ft_printf("%C /", 0xf1bb);
		check_nl(g_arr[2]);
	}
	ft_putstr("$>");
	ft_putstr(C_DEF);
}
