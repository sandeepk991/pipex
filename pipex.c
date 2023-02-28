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

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	pipeid[2];
	int	status;

	if (ac == 5)
	{
		if (pipe(fd) < 0)
			ft_perror();
		pipe_child1(pipeid, fd, av, envp);
		pipe_child2(pipeid, fd, av, envp);
		close(pipeid[0]);
		close(pipeid[1]);
		waitpid(-1, &status, 0);
		waitpid(-1, &status, 0);
	}
	else
		ft_perror();
	return (0);
}

void	pipe_child1(int *pipeid, int *fd, char **av, char **envp)
{
	char	**cmd1;
	int		cmd_pid;

	cmd_pid = fork();
	if (cmd_pid < 0)
		ft_perror();
	if (cmd_pid == 0)
	{
		fd[0] = open(av[1], O_RDONLY);
		if (fd[0] < 0)
			ft_perror();
		cmd1 = ft_split(av[2], ' ');
		close(pipeid[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipeid[1], STDOUT_FILENO);
		if (cmd1[0] && cmd_path(cmd1[0], envp))
		{
			execve(cmd_path(cmd1[0], envp), cmd1, envp);
			free_split(cmd1);
		}
		else
			cmd_not_found(cmd1);
	}
}

void	pipe_child2(int *pipeid, int *fd, char **av, char **envp)
{
	char	**cmd2;
	int		cmd_pid;

	cmd_pid = fork();
	if (cmd_pid < 0)
		ft_perror();
	if (cmd_pid == 0)
	{
		fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] < 0)
			ft_perror();
		cmd2 = ft_split(av[3], ' ');
		close(pipeid[1]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipeid[0], STDIN_FILENO);
		if (cmd2[0] && cmd_path(cmd2[0], envp))
		{
			execve(cmd_path(cmd2[0], envp), cmd2, envp);
			free_split(cmd2);
		}
		else
			cmd_not_found(cmd2);
	}
}
