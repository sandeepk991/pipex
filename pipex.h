#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "libft.h"

char	*path(char *cmd, char **envp);
void	usage(void);
void	terminate(char *m);
void	free_split(char **args);
void	cmd_not_found(char **cmd);

#endif

