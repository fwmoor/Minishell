/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:41 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/06 10:48:39 by fremoor          ###   ########.fr       */
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
			str2 = readline(C_GREEN"dquote$>"C_DEFAULT);
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

void			sigint_handler() {
	ft_putendl("test");
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
	pop_env(env);
	while (i)
	{
		signal(SIGINT, sigint_handler);
		get_dir_path(g_env);
		line = readline(" ");
		line = end_quote(line);
		add_history(line);
		commands = ft_strsplit(line, ';');
		free(line);
		i = exec_args(commands);
		free(commands);
	}
	free_her(g_env);
}
