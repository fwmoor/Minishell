/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:12:13 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/21 09:22:15 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char			**sys_quotes(char *str, char c)
{
	int			i;
	char		**ret;

	i = 0;
	while (str[i] && c != ' ')
	{
		if (str[i] == c)
		{
			i++;
			while (str[i] != c)
				i++;
		}
		if (str[i] == ' ' || str[i] == '\t')
			str[i] = c;
		i++;
	}
	ret = ft_strsplit(str, c);
	return (ret);
}

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
	int			len;
	char		c;
	char		*ret;

	i = 0;
	i1 = 0;
	len = 0;
	c = which_quote(str);
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
		if (!ft_strequ(buf, "/"))
		{
			home = get_env("HOME=");
			setenv_var("PWD", buf);
			if (ft_strstr(buf, home))
				ft_printf("~%s", ft_strstr(buf, home) + ft_strlen(home));
			else
				ft_printf("%s", buf);
			free(home);
		}
		else
			ft_putchar('/');
		check_nl(g_arr[2]);
	}
	ft_putstr("$>");
	ft_putstr(C_DEF);
}
