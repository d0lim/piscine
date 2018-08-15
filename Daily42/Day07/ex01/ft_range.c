/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:22:11 by dolim             #+#    #+#             */
/*   Updated: 2018/08/01 16:37:58 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*arr;
	int		count;

	count = 0;
	if (min >= max)
		return (0);
	arr = (int*)malloc(sizeof(int) * (max - min));
	while (min != max)
	{
		*(arr++) = min++;
		count++;
	}
	arr -= count;
	return (arr);
}
