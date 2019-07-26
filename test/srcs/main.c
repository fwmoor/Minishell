#include "../includes/minishell.h"

int				main(int ac, char **av, char **env)
{
	int			i;
	char		*line;
	char		**commands;

	(void)ac;
	(void)av;
	(void)env;
	i = 1;
	system("clear");
	while (i)
	{
		ft_printf("\033[32;1m$>\033[0m ");
		get_next_line(0, &line);
		commands = ft_strsplit(line, ' ');
		free(line);
		i = exec_args(commands);
		free (commands);
	}
	// char *oldenv = strdup(getenv("PATH"));
	// setenv("PATH", "hello", 1);
	// system("echo $PATH");
	// setenv("PATH", oldenv, 1);
	// free(oldenv);
	// system("echo $PATH");
}
