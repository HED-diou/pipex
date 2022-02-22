/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-diou <hed-diou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:44:50 by hed-diou          #+#    #+#             */
/*   Updated: 2021/12/21 16:15:24 by hed-diou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	is_in(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	is_in_set(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!is_in(set, s1[i]))
			return (0);
		i++;
	}
	return (1);
}

static char	*trimx(int k, int i, char *str, const char *s1)
{
	int		x;

	x = 0;
	while (k < i)
	{
		str[x] = s1[k];
		k++;
		x++;
	}
	str[x] = '\0';
	return (str);
}

char	*ft_strtrim(const char *s1, const char *set)
{	
	int		i;
	int		k;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	k = 0;
	if (s1)
	{
		if (is_in_set(s1, set))
			return (ft_strdup(""));
		while (s1[i])
			i++;
		while (is_in(set, s1[k]))
			k++;
		while (is_in(set, s1[i - 1]))
			i--;
		str = malloc(sizeof(char) * (i - k + 1));
		if (!str)
			return (NULL);
		free((char *)s1);
		return (trimx(k, i, str, s1));
	}
	return (0);
}
