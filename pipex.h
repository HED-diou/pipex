/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-diou <hed-diou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:33:16 by hed-diou          #+#    #+#             */
/*   Updated: 2021/12/21 22:33:19 by hed-diou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "pipex.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strdup(char *t1);
size_t	ft_strlen(const char *str);
char	*get_path(char *cmd, char **envp);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**par(char **argv, int index);

#endif