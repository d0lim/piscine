/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbixby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 10:52:57 by brbixby           #+#    #+#             */
/*   Updated: 2018/08/12 11:34:43 by brbixby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, &*str++, 1);
}

int		ft_geth(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int		ft_gett(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr(int i)
{
	long int	num;
	int			denom;

	num = i;
	denom = 10;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (num >= 10)
	{
		while (num / denom >= 10)
			denom *= 10;
		while (num >= 10)
		{
			ft_putchar(num / denom + 48);
			num %= denom;
			denom /= 10;
		}
	}
	ft_putchar(num + 48);
}
