/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-diou <hed-diou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:09:38 by hed-diou          #+#    #+#             */
/*   Updated: 2021/12/21 22:43:23 by hed-diou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "pipex.h"

char	*ft_strnstr(char *big, char *little, size_t len )
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	if (ft_strlen(little) == 0)
		return (big);
	while (big[i] && i < len)
	{
		j = 0;
		tmp = i;
		while (big[tmp] == little[j] && little[j] != '\0')
		{
			if (little[j + 1] == '\0' && tmp < len)
				return (&big[i]);
			j++;
			tmp++;
		}
		i++;
	}
	return (0);
}

int	ft_pathindex(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != NULL)
			return (i);
		i++;
	}
	return (0);
}

void	ft_free2(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free (argv[i]);
		i++;
	}
	free (argv);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*res;
	char	**path;

	i = -1;
	path = ft_split(envp[ft_pathindex(envp)], ':');
	path[0] = ft_strtrim(path[0], "PATH=");
	while (path[++i])
		path[i] = ft_strjoin(path[i], "/");
	i = -1;
	while (path[++i])
	{
		res = ft_strjoin(path[i], cmd);
		if (access(res, F_OK) == 0)
		{
			if (access(res, X_OK) == 0)
				return (res);
			return (res);
		}
		free(res);
	}
	return (NULL);
}
