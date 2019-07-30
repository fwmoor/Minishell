/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:32 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/30 09:13:19 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char			*get_dir_path(char **env)
{
	char		*home;
	char		*ret;
	char		buf[4097];

	getcwd(buf, 4096);
	home = get_env("HOME=", env);
	ret = ft_strdup(ft_strstr(buf, home) + ft_strlen(home));
	free(home);
	return(ret);
}

int				exec_cd(char *arg, char **env)
{
	char		*ret;
	char		*home;
	char		**dirs;

	dirs = ft_strsplit(arg, ' ');
	if (dirs[1] == NULL)
	{
		home = get_env("HOME=", env);
		ret = ft_strdup(home);
		free(home);
	}
	else
		ret = ft_strdup(dirs[1]);
	free_her(dirs);
	chdir(ret);
	free(ret);
	free(arg);
	return (1);
}
