/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:35:47 by dolim             #+#    #+#             */
/*   Updated: 2018/08/03 16:35:50 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if ((base % 2) == 0)
		return (ft_collatz_conjecture(base / 2));
	else
		return (ft_collatz_conjecture(3 * base + 1));
}
