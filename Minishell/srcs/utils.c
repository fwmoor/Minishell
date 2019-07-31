/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:12:13 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/31 13:46:58 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		**remove_quotes(char *str)
{
	int		i;
	char	**ret;
	
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
	free(str);
	return (ret);
}

void		free_her(char **dirs)
{
	int		i;

	i = 0;
	while (dirs[i])
		free(dirs[i++]);
	free(dirs);
}

char		*get_env(char *str, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(str, env[i], ft_strlen(str)) == 0)
			return (ft_strdup(ft_strchr(env[i], '=') + 1));
		i++;
	}
	return (NULL);
}

void			get_dir_path(char **env)
{
	char		*home;
	char		buf[4097];

	getcwd(buf, 4096);
	home = get_env("HOME=", env);
	ft_printf("\033[32;1m~%s$>\033[0m", ft_strstr(buf, home) + ft_strlen(home));
	free(home);
}
