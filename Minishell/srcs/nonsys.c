#include "../includes/minishell.h"

int         exec_cd(char *arg)
{
    chdir(arg);
    return (1);
}