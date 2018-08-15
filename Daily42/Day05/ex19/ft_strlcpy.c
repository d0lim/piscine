/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 00:21:29 by dolim             #+#    #+#             */
/*   Updated: 2018/07/31 01:13:31 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (i < (int)size - 1)
	{
		*dest = *src;
		dest++;
		src++;
		count++;
	}
	*dest = '\0';
	while (src != '\0')
	{
		src++;
		count++;
	}
	return (count);
}
