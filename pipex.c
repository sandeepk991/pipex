/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:49:41 by skaur             #+#    #+#             */
/*   Updated: 2023/02/28 11:39:49 by skaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void     ft_close_fd(int *fd, int *fd_pipeid);
static int      pipex(char **av, char *const *envp, int *fd);
static void     pipe_child1(char **av, char *const *envp, int *fd_pipeid, int *fd);
static void     pipe_child2(char **av, char *const *envp, int *fd_pipeid, int *fd);

int     main(int ac, char **av, char *const *envp)
{
        int     fd[2];
        int     status;

        if (ac == 5)
        {
                fd[0] = open(av[1], O_RDONLY);
                if (fd[0] < 0)
                        ft_perror(av[1]);
                fd[1] = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
                if (fd[1] < 0)
                        ft_perror(av[4]);
                status = pipex(av, envp, fd);
                exit(status);
        }
        else
        {
                usage();
        }
        return (0);
}

static int      pipex(char **av, char *const *envp, int *fd)
{
        pid_t   pid1;
        pid_t   pid2;
        int             fd_pipeid[2];
        int             status;

        status = 0;
        if (pipe(fd_pipeid) == -1)
                ft_perror("Pipe: ");
        pid1 = fork();
        if (pid1 < 0)
                ft_perror("Fork: ");
        if (pid1 == 0)
                pipe_child1(av, envp, fd_pipeid, fd);
        pid2 = fork();
        if (pid2 < 0)
                ft_perror("Fork: ");
        if (pid2 == 0)
                pipe_child2(av, envp, fd_pipeid, fd);
        ft_close_fd(fd, fd_pipeid);
        waitpid(pid1, NULL, 0);
        waitpid(pid2, &status, 0);
        return (WEXITSTATUS(status));
}

static void	pipe_child1(char **av, char *const *envp, int *fd_pipeid, int *fd)
{
	char	**cmd;
	char	*path;
	int		status;

	status = 0;
	if (dup2(fd[0], STDIN_FILENO) < 0)
		exit(EXIT_FAILURE);
	if (dup2(fd_pipeid[1], STDOUT_FILENO) < 0)
		exit(EXIT_FAILURE);
	ft_close_fd(fd, fd_pipeid);
	cmd = ft_split(av[2], ' ');
	path = cmd_path(cmd[0], envp);
	if (cmd && path)
		execve(path, cmd, envp);
	else
	{
		cmd_not_found(cmd);
	}
	free(path);
	free_split(cmd);
	exit(status);
}

static void	pipe_child2(char **av, char *const *envp, int *fd_pipeid, int *fd)
{
	char	**cmd;
	char	*path;
	int		status;

	status = 0;
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		exit(EXIT_FAILURE);
	if (dup2(fd_pipeid[0], STDIN_FILENO) < 0)
		exit(EXIT_FAILURE);
	ft_close_fd(fd, fd_pipeid);
	cmd = ft_split(av[3], ' ');
	path = cmd_path(cmd[0], envp);
	if (cmd && path)
		execve(path, cmd, envp);
	else
	{
		cmd_not_found(cmd);
	}
	free(path);
	free_split(cmd);
	exit(status);
}

static void     ft_close_fd(int *fd, int *fd_pipeid)
{
        close(fd[0]);
        close(fd[1]);
        close(fd_pipeid[0]);
        close(fd_pipeid[1]);
}
