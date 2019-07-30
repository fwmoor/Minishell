/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:41 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/30 20:15:22 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			end_quote(char *str, char *ptr)
{
	char		*temp;
	char		*str2;

	while ((ptr = ft_strchr(ptr, '"')) != NULL)
	{
		++ptr;
		if ((ptr = ft_strchr(ptr, '"')) == NULL)
		{
			ft_putstr("\033[1;32m");
			str2 = readline("dquote$>");
			ft_putstr("\033[0m");
			temp = ft_strjoin(str, "\n");
			ft_strdel(&str);
			str = ft_strjoin(temp, str2);
			free(temp);
			ft_strdel(&str2);
			ptr = str;
		}
		else
			ptr++;
	}
}

int				main(int ac, char **av, char **env)
{
	int			i;
	char		*line;
	char		*home;
	char		*ptr;
	char		**commands;

	(void)ac;
	(void)av;
	i = 1;
	system("clear");
	while (i)
	{
		home = get_dir_path(env);
		ft_printf("\033[32;1m~%s", home);
		line = readline("$>\033[0m ");
		ptr = line;
		end_quote(line, ptr);
		if (line && *line)
			add_history(line);
		commands = ft_strsplit(line, ';');
		i = exec_args(commands, env);
		free(line);
		free(home);
		free(commands);
	}
}
