/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:41 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/13 12:57:44 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char			*end_quote(char *str, char c)
{
	char		*ptr;
	char		*temp;
	char		*str2;

	ptr = str;
	while ((ptr = ft_strchr(ptr, c)) != NULL)
	{
		if ((ptr = ft_strchr(++ptr, c)) == NULL)
		{
			check_colour(g_arr[0]);
			if (c == '\'')
				str2 = readline("quote$>"C_DEF);
			else
				str2 = readline("dquote$>"C_DEF);
			temp = ft_strjoin(str, "\n");
			ft_strdel(&str);
			str = ft_strjoin(temp, str2);
			delfunc_quote(str2, temp);
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

void			zsh_level(void)
{
	char		*temp;
	char		*lvl;

	temp = get_env("SHLVL=");
	lvl = ft_itoa(ft_atoi(temp) + 1);
	setenv_var("SHLVL", lvl);
	free(temp);
	free(lvl);
}

void			get_config(int ac, char **av)
{
	int			fd;
	char		*line;
	char		**cons;

	(void)ac;
	(void)av;
	fd = open("./includes/config/config", O_RDONLY);
	if (fd != -1)
		while (get_next_line(fd, &line) > 0)
		{
			if (line[0] != '#' && line)
			{
				cons = ft_strsplit(line, '=');
				if (ft_strequ(cons[0], "COLOUR"))
					g_arr[0] = ft_strdup(cons[1]);
				if (ft_strequ(cons[0], "ENDNL"))
					g_arr[1] = ft_strdup(cons[1]);
				if (ft_strequ(cons[0], "MULTILINE"))
					g_arr[2] = ft_strdup(cons[1]);
				if (ft_strequ(cons[0], "PATH"))
					g_arr[3] = ft_strdup(cons[1]);
				free_her(cons);
			}
			free(line);
		}
}

int				main(int ac, char **av, char **env)
{
	int			i;
	char		c;
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
		c = quote_thing(line);
		if (c == '\'' || c == '"')
			line = end_quote(line, c);
		add_history(line);
		commands = ft_strsplit(line, ';');
		free(line);
		i = exec_args(commands);
		(i > 0) ? check_nl(g_arr[1]) : 0;
	}
	free_her(g_env);
}
