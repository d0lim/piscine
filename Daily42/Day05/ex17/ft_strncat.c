/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 22:34:18 by dolim             #+#    #+#             */
/*   Updated: 2018/07/30 22:38:33 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (*dest != '\0')
	{
		dest++;
		count++;
	}
	while (i < nb)
	{
		*dest = *src;
		dest++;
		src++;
		count++;
		i++;
	}
	*dest = '\0';
	return (dest - count);
}
