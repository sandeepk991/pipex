/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_eval.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:47:01 by skaur             #+#    #+#             */
/*   Updated: 2023/02/17 13:08:34 by skaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
{
	char	**cmd_path;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	cmd_path = ft_split(envp[i] + 5, ':');
	return (cmd_path);
}

char	*cmd_path(char *cmd, char **envp)
{
	char	**envp_paths;
	char	*exec_path;
	char	*slash;
	int		i;

	i = 0;
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (cmd);
	envp_paths = get_path(envp);
	i = -1;
	while (envp_paths[++i])
	{
		slash = ft_strjoin(envp_paths[i], "/");
		exec_path = ft_strjoin(slash, cmd);
		free(slash);
		if (!access(exec_path, F_OK))
		{
			free_split(envp_paths);
			return (exec_path);
		}
		free(exec_path);
	}
	free_split(envp_paths);
	return (0);
}
