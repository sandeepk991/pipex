/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:30:13 by skaur             #+#    #+#             */
/*   Updated: 2023/02/28 12:17:36 by skaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

size_t	ft_strlen(const char *s);
char	*cmd_path(char *cmd, char **envp);
char	**get_path(char **envp);
char	*ft_strnstr(const char *str, const char *find, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_perror(void);
void	free_split(char **args);
void	cmd_not_found(char **cmd);
void	pipe_child1(int *pipeid, int *fd, char **av, char **envp);
void	pipe_child2(int *pipeid, int *fd, char **av, char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
