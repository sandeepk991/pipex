/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:46:36 by skaur             #+#    #+#             */
/*   Updated: 2023/02/17 15:09:42 by skaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *m)
{
	if (errno == 0)
		write(2, "Error\n", 6);
	else
		perror(m);
	exit(EXIT_FAILURE);
}

void	cmd_not_found(char **cmd)
{
	write(2, cmd[0], ft_strlen(cmd[0]));
	write(2, ": command not found\n", 20);
	free_split(cmd);
	exit(EXIT_FAILURE);
}

void	free_split(char **args)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (args[size])
		size++;
	while (i < size)
		free(args[i++]);
	free(args);
}

void	usage(void)
{
	write(2, "usage: ./pipex [file1] [cmd1] [cmd2] [file2]\n", 45);
	exit(1);
}
