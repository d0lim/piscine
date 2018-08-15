/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 00:54:25 by dolim             #+#    #+#             */
/*   Updated: 2018/07/31 00:54:39 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_printnbr_first(int cnb)
{
	if (cnb >= 1000000000)
		ft_putchar(cnb / 1000000000 + 48);
	if (cnb >= 100000000)
		ft_putchar((cnb % 1000000000) / 100000000 + 48);
	if (cnb >= 10000000)
		ft_putchar((cnb % 100000000) / 10000000 + 48);
	if (cnb >= 1000000)
		ft_putchar((cnb % 10000000) / 1000000 + 48);
	if (cnb >= 100000)
		ft_putchar((cnb % 1000000) / 100000 + 48);
	if (cnb >= 10000)
		ft_putchar((cnb % 100000) / 10000 + 48);
	if (cnb >= 1000)
		ft_putchar((cnb % 10000) / 1000 + 48);
	if (cnb >= 100)
		ft_putchar((cnb % 1000) / 100 + 48);
	if (cnb >= 10)
		ft_putchar((cnb % 100) / 10 + 48);
}

void	ft_putnbr(int nb)
{
	int cnb;
	int flag;

	flag = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			nb = nb + 1;
			flag = 1;
		}
		cnb = nb * (-1);
		ft_putchar('-');
	}
	else
		cnb = nb;
	ft_printnbr_first(cnb);
	if (flag == 1)
		ft_putchar(cnb % 10 + 49);
	else
		ft_putchar(cnb % 10 + 48);
}
