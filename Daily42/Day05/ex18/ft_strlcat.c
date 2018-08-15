/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 22:59:01 by dolim             #+#    #+#             */
/*   Updated: 2018/07/31 05:19:49 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dlen;
	unsigned int	slen;

	slen = 0;
	dlen = 0;
	while (*src != '\0')
	{
		slen++;
		src++;
	}
	src -= slen;
	while (*dest && size > 0)
	{
		dest++;
		dlen++;
		size--;
	}
	while (*src && size-- > 1)
		*dest++ = *src++;
	if (size == 1 || *src == 0)
		*dest = '\0';
	return (dlen + slen);
}
