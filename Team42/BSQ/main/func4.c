/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <dolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 03:27:48 by dolim             #+#    #+#             */
/*   Updated: 2018/08/15 03:37:01 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	info_realloc(char **info_string, char buf)
{
	int		i;

	i = 0;
	while ((*info_string)[i] != '\0')
		i++;
	*info_string = recalloc(*info_string, sizeof(char) * (i + 1));
	(*info_string)[i] = buf;
	(*info_string)[i + 1] = 0;
}

void	read_info(t_lc *lc, char *info_string)
{
	int		i;
	int		j;

	i = 0;
	while (info_string[i] != '\0')
		i++;
	lc->info[0] = info_string[i - 3];
	lc->info[1] = info_string[i - 2];
	lc->info[2] = info_string[i - 1];
	j = 0;
	while (j < i - 3)
	{
		lc->line = lc->line * 10 + (info_string[j] - '0');
		j++;
	}
}
