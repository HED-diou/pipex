/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-diou <hed-diou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:34:19 by hed-diou          #+#    #+#             */
/*   Updated: 2021/12/21 22:30:51 by hed-diou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**par(char **argv, int index)
{
	char	**ag;

	ag = ft_split(argv[index], ' ');
	return (ag);
}