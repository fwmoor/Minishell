/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:23:06 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/06 19:31:52 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			proc_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		signal(SIGINT, proc_signal_handler);
	}
}

char			*do_path(char *bin, char *com)
{
	char		*temp;
	char		*path;

	if (ft_strstr(bin, com) != NULL)
		path = ft_strdup(com);
	else
	{
		temp = ft_strjoin(bin, "/");
		path = ft_strjoin(temp, com);
		ft_strdel(&temp);
	}
	return (path);
}

char			*get_path(char *com)
{
	int			i;
	char		*temp;
	char		**bin;
	char		*path;
	struct stat	info;

	i = -1;
	temp = get_env("PATH=");
	bin = ft_strsplit(temp, ':');
	ft_strdel(&temp);
	while (bin && bin[++i])
	{
		path = do_path(bin[i], com);
		if (lstat(path, &info) == -1)
			free(path);
		else
		{
			free_her(bin);
			return (path);
		}
	}
	if (bin != NULL)
		free_her(bin);
	return (NULL);
}

int				exec_sys(char *com)
{
	pid_t		pid;
	char		*path;
	char		**temp;

	temp = remove_quotes(com);
	path = get_path(temp[0]);
	if (path != NULL)
	{
		signal(SIGINT, proc_signal_handler);
		if (!(pid = fork()))
			execve(path, temp, g_env);
		wait(&pid);
	}
	else
		ft_printf("minishell: command not found: %s\n", com);
	free(path);
	ft_strdel(&com);
	free_her(temp);
	return (1);
}
