/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:12:13 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/30 09:51:43 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

char			*get_dir_path(char **env)
{
	char		*home;
	char		*ret;
	char		buf[4097];

	getcwd(buf, 4096);
	home = get_env("HOME=", env);
	ret = ft_strdup(ft_strstr(buf, home) + ft_strlen(home));
	free(home);
	return (ret);
}
