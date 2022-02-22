/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-diou <hed-diou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:47:39 by hed-diou          #+#    #+#             */
/*   Updated: 2021/12/15 13:54:31 by hed-diou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *t1)
{
	int		n;
	char	*t2;
	int		i;

	n = 0;
	while (t1[n])
		n++;
	t2 = (char *)malloc((n + 1) * sizeof(char));
	if (t2 == NULL)
		return (0);
	i = 0;
	while (t1[i])
	{
		t2[i] = t1[i];
		i++;
	}
	t2[i] = '\0';
	return (t2);
}
