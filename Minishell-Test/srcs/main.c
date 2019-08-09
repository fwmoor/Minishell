/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:41 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/09 17:12:07 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			free_glob(void)
{
	free(e_nl);
	free(m_lines);
	free(c_con);
	free(s_path);
}

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

	(void)ac;
	(void)av;
	fd = open("config/config", O_RDONLY);
	if (fd == -1)
		c_con = ft_strdup("Default");
	else
		while (get_next_line(fd, &line) > 0)
		{
			if (ft_strnequ(line, "COLOUR=", 7))
				c_con = ft_strdup(ft_strstr(line, "COLOUR=") + 7);
			if (ft_strnequ(line, "ENDNL=", 6))
				e_nl = ft_strdup(ft_strstr(line, "ENDNL=") + 6);
			if (ft_strnequ(line, "MULTILINE=", 10))
				m_lines = ft_strdup(ft_strstr(line, "MULTILINE=") + 10);
			if (ft_strnequ(line, "PATH=", 5))
				s_path = ft_strdup(ft_strstr(line, "PATH=") + 5);
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
		check_nl(e_nl);
	}
	free_glob();
	free_her(g_env);
}
