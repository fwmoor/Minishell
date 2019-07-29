/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:41 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/29 19:41:54 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char			*get_dir_path(char **env)
{
	char		*home;
	char		buf[4097];

	getcwd(buf, 4096);
	home = get_env("HOME=", env);
	return(ft_strstr(buf, home) + ft_strlen(home));
}

int				main(int ac, char **av, char **env)
{
	int			i;
	char		*line;
	char		**commands;

	(void)ac;
	(void)av;
	i = 1;
	system("clear");
	while (i)
	{
		get_dir_path(env);
		ft_printf("\033[32;1m~%s$>\033[0m ", get_dir_path(env));
		get_next_line(0, &line);
		commands = ft_strsplit(line, ';');
		free(line);
		i = exec_args(commands, env);
		free(commands);
	}
}
