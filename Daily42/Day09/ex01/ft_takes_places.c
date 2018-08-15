/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_places.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:35:07 by dolim             #+#    #+#             */
/*   Updated: 2018/08/03 16:35:10 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	int		h1;
	int		h2;
	int		hr1;
	int		hr2;

	h1 = hour;
	h2 = ((hour + 1) == 24 ? 0 : (hour + 1));
	hr1 = 0;
	hr2 = 0;
	if (h1 >= 12)
	{
		h1 = h1 - 12;
		hr1 = 1;
	}
	if (h2 >= 12)
	{
		h2 = h2 - 12;
		hr2 = 1;
	}
	h1 = (h1 == 0 ? 12 : h1);
	h2 = (h2 == 0 ? 12 : h2);
	printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 %s AND %d.00 %s\n", h1,
			(hr1 == 0 ? "A.M." : "P.M."), h2, (hr2 == 0 ? "A.M." : "P.M."));
}
