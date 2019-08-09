/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:12:13 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/09 17:11:31 by fwmoor           ###   ########.fr       */
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

void			free_her(char **dirs)
{
	int			i;

	i = 0;
	while (dirs[i])
		ft_strdel(&dirs[i++]);
	free(dirs);
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
	check_colour(c_con);
	if (ft_strequ(s_path, "True"))
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
		check_nl(m_lines);
	}
	ft_putstr("$>");
	ft_putstr(C_DEF);
}
