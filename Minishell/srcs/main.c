/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:41 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/30 08:05:19 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char			*get_dir_path(char **env)
{
	char		*home;
	char		buf[4097];

	getcwd(buf, 4096);
	home = get_env("HOME=", env);
	return(ft_strdup(ft_strstr(buf, home) + ft_strlen(home)));
}

int				main(int ac, char **av, char **env)
{
	int			i;
	char		*line;
	char		*home;
	char		**commands;

	(void)ac;
	(void)av;
	i = 1;
	system("clear");
	while (i)
	{
		home = get_dir_path(env);
		ft_printf("\033[32;1m~%s$>\033[0m ", home);
		get_next_line(0, &line);
		commands = ft_strsplit(line, ';');
		free(line);
		free(home);
		i = exec_args(commands, env);
		free(commands);
	}
}
