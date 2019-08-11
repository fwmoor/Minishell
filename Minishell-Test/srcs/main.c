/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:41 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/11 20:01:59 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char			*end_quote(char *str)
{
	char		*ptr;
	char		*temp;
	char		*str2;

	ptr = str;
	while ((ptr = ft_strchr(ptr, '"')) != NULL)
	{
		++ptr;
		if ((ptr = ft_strchr(ptr, '"')) == NULL)
		{
			check_colour(con_arr[0]);
			str2 = readline("dquote$>"C_DEF);
			temp = ft_strjoin(str, "\n");
			ft_strdel(&str);
			str = ft_strjoin(temp, str2);
			ft_strdel(&str2);
			ft_strdel(&temp);
			ptr = str;
		}
		else
			ptr++;
	}
	return (str);
}

void			sigint_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		get_dir_path();
		signal(SIGINT, sigint_handler);
	}
}

void			get_config(int ac, char **av)
{
	int			fd;
	char		*line;
	char		**cons;

	(void)ac;
	(void)av;
	fd = open("config/config", O_RDONLY);
	if (fd != -1)
		while (get_next_line(fd, &line) > 0)
		{
			if (line[0] != '#' && line)
			{
				cons = ft_strsplit(line, '=');
				if (ft_strequ(cons[0], "COLOUR"))
					con_arr[0] = ft_strdup(cons[1]);
				if (ft_strequ(cons[0], "ENDNL"))
					con_arr[1] = ft_strdup(cons[1]);
				if (ft_strequ(cons[0], "MULTILINE"))
					con_arr[2] = ft_strdup(cons[1]);
				if (ft_strequ(cons[0], "PATH"))
					con_arr[3] = ft_strdup(cons[1]);
				free_her(cons);
			}
			free(line);
		}
}

int				main(int ac, char **av, char **env)
{
	int			i;
	char		*line;
	char		**commands;

	i = 1;
	get_config(ac, av);
	pop_env(env);
	while (i)
	{
		get_dir_path(g_env);
		signal(SIGINT, sigint_handler);
		line = readline(" ");
		line = end_quote(line);
		add_history(line);
		commands = ft_strsplit(line, ';');
		free(line);
		i = exec_args(commands);
		free(commands);
		(i > 0) ? check_nl(con_arr[1]) : 0;
	}
	free_her(g_env);
}
