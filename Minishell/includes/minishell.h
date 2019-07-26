#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"

int		    main(int ac, char **av, char **env);
int         exec_args(char **av, char **env);
char		*get_env(char *str, char **env);

#endif
