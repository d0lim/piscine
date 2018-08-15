/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:08:06 by dolim             #+#    #+#             */
/*   Updated: 2018/07/28 22:41:53 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int		base;
	int		i;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 0;
	base = 1;
	while (i < power)
	{
		base *= nb;
		i = i + 1;
	}
	return (base);
}
