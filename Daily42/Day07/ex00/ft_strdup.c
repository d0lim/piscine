/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:12:05 by dolim             #+#    #+#             */
/*   Updated: 2018/08/02 22:25:25 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		count;
	char	*dest;

	count = 0;
	while (*src != '\0')
	{
		src++;
		count++;
	}
	src -= count;
	dest = (char*)malloc(sizeof(char) * count);
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	dest -= count;
	return (dest);
}
