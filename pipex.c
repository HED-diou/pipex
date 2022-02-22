/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-diou <hed-diou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:09:31 by hed-diou          #+#    #+#             */
/*   Updated: 2021/12/21 23:06:07 by hed-diou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "pipex.h"
#include <sys/wait.h>

void	error_exeption(char *error)
{
	perror(error);
	exit(1);
}

void	fork_chile_1(char *av1, char *av2, char **envp, int *fd)
{
	int		fl1;
	char	**cmd;

	fl1 = open(av1, O_RDONLY, 0777);
	if (fl1 == -1)
		error_exeption("no such file or directory");
	if (dup2(fl1, 0) == -1)
		error_exeption("dup2 fl1");
	if (dup2(fd[1], 1) == -1)
		error_exeption("dup2 fd");
	if (close(fd[0]) == -1)
		error_exeption("close fd");
	if (close(fd[1]) == -1)
		error_exeption("close fd");
	if (close(fl1) == -1)
		error_exeption("close fl1");
	cmd = ft_split(av2, ' ');
	if (execve(get_path(cmd[0], envp), cmd, NULL))
		error_exeption("execve chile 1");
}

void	fork_chile_2(char *av3, char *av4, char **envp, int *fd)
{
	int		fl;
	char	**cmd;

	fl = open(av4, O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fl == -1)
		error_exeption("");
	if (dup2(fd[0], 0) == -1)
		error_exeption("dup2 fd");
	if (dup2(fl, 1) == -1)
		error_exeption("dup2 fl");
	if (close(fd[1]) == -1)
		error_exeption("close fd 1");
	if (close(fd[0]) == -1)
		error_exeption("close fd 0");
	if (close(fl) == -1)
		error_exeption("close fl");
	cmd = ft_split(av3, ' ');
	if (execve(get_path(cmd[0], envp), cmd, NULL))
		error_exeption("execve chile 2");
}

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	id2;
	int	id;

	if (ac != 5)
	{
		error_exeption("invalid arguments");
		return (0);
	}
	pipe(fd);
	id = fork();
	if (id == -1)
		error_exeption("fork 1");
	if (id == 0)
		fork_chile_1(av[1], av[2], envp, fd);
	id2 = fork();
	if (id2 == -1)
		error_exeption("fork 2");
	if (id2 == 0)
		fork_chile_2(av[3], av[4], envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(id, NULL, 0);
	waitpid(id2, NULL, 0);
}
