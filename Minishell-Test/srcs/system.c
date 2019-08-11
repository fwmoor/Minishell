/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:23:06 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/11 20:18:10 by fwmoor           ###   ########.fr       */
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

int				sys_call(char **coms, char *path)
{
	pid_t		pid;

	signal(SIGINT, proc_signal_handler);
	pid = fork();
	if (!pid)
	{
		if (execve(path, coms, g_env) == -1)
			ft_printf("minishell: premission denied: %s\n", path);
	}
	else if (pid < 0)
		ft_printf("minishell: unable to fork process: %d\n", pid);
	else
		wait(&pid);
	return (1);
}

int				exec_sys(char **coms)
{
	char		*temp;
	char		*path;
	struct stat	info;

	path = get_path(coms[0]);
	if (path != NULL && coms[0][0] != '~')
		return(sys_call(coms, path));
	else if (coms[0][0] == '~')
	{
		free(path);
		return(tilda_cd(coms[0]));
	}
	if (lstat(coms[0], &info) != -1)
	{
		if (S_ISREG(info.st_mode))
		{
			temp = ft_strdup(coms[0]);
			sys_call(coms, temp);
			free(temp);
		}
	}
	else
		ft_printf("minishell: command not found: %s\n", coms[0]);
	return (1);
}
