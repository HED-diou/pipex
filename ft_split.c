/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-diou <hed-diou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:47:53 by hed-diou          #+#    #+#             */
/*   Updated: 2021/12/21 22:29:17 by hed-diou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	spl(const char *s, char c)
{
	int	i;
	int	spl;

	i = 0;
	spl = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			spl++;
			while (s[i] && s[i] != c)
				i++;
			i--;
		}
		i++;
	}
	return (spl);
}

static int	len(const char *s, int i, char c)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

void	ft_free(char **cpy, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free (cpy[i]);
		j++;
	}
	free(cpy);
}

static char	**engine(int k, char **cpy, const char *s, char c)
{
	int	i;
	int	ii;
	int	l;
	int	j;

	i = 0;
	ii = 0;
	while (i < k && s[ii])
	{
		while (s[ii] == c)
			ii++;
		l = len(s, ii, c);
		cpy[i] = (char *)malloc(sizeof(char) * (l + 1));
		if (!(cpy[i]))
		{
			ft_free(cpy, i);
			return (NULL);
		}
		j = 0;
		while (s[ii] != c && s[ii])
				cpy[i][j++] = s[ii++];
		cpy[i++][j] = '\0';
	}
	cpy[i] = NULL;
	return (cpy);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		k;
	char	**cpy;

	i = 0;
	if (s)
	{
		k = spl(s, c);
		cpy = (char **)malloc(sizeof(char *) * (k + 1));
		if (!cpy)
			return (NULL);
		return (engine(k, cpy, s, c));
		return (cpy);
	}
	return (0);
}
