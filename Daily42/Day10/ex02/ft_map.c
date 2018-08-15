/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 23:00:11 by dolim             #+#    #+#             */
/*   Updated: 2018/08/07 23:39:59 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ft_map(int *tab, int length, int(*f)(int))
{
	int i;
	int *r;

	i = 0;
	if ((r = (int *)malloc(sizeof(int) * length)) == NULL)
		return (NULL);
	while (i < length)
	{
		r[i] = f(tab[i]);
		i++;
	}
	return (r);
}
