/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 16:06:51 by dolim             #+#    #+#             */
/*   Updated: 2018/07/28 22:51:07 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		rt;
	int		shit;

	if (nb < 0)
		return (0);
	if (nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	rt = 1;
	shit = nb;
	while (shit > 0)
	{
		rt = rt * shit;
		shit = shit - 1;
	}
	return (rt);
}
