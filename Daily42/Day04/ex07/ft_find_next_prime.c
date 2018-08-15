/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 19:13:49 by dolim             #+#    #+#             */
/*   Updated: 2018/07/28 23:17:41 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int		i;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (0);
	if (nb == 1)
		return (0);
	if (nb == 2)
		return (1);
	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i = i + 1;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int		next;

	next = nb;
	while (next <= 2147483647)
	{
		if (ft_is_prime(next) == 1)
			return (next);
		next = next + 1;
	}
	return (0);
}
