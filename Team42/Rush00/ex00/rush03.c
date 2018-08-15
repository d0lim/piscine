/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 02:15:09 by lyoung-j          #+#    #+#             */
/*   Updated: 2018/07/29 11:47:15 by callen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		edge_case(int size, char rc, char lc)
{
	if (size == 1)
	{
		ft_putchar(rc);
		ft_putchar('\n');
		return (1);
	}
	if (size == 2)
	{
		ft_putchar(rc);
		ft_putchar(lc);
		ft_putchar('\n');
		return (1);
	}
	return (0);
}

void	rushtop(int size, char rc, char m, char lc)
{
	int i;

	if (edge_case(size, rc, lc) == 1)
		return ;
	i = 0;
	while (i < size)
	{
		if (i == 0)
			ft_putchar(rc);
		else if (i == (size - 1))
			ft_putchar(lc);
		else
			ft_putchar(m);
		i++;
	}
	ft_putchar('\n');
	return ;
}

void	rushmid(int w, int h, char c)
{
	int x;

	x = w;
	while (h >= 1)
	{
		x = w;
		while (x >= 1)
		{
			if (x == 1 || x == w)
				ft_putchar(c);
			else
				ft_putchar(' ');
			x--;
		}
		ft_putchar('\n');
		h--;
	}
}

void	ft_rushbot(int x, char first, char mid, char last)
{
	int		i;
	char	a;
	char	b;
	char	c;

	i = 0;
	a = first;
	b = mid;
	c = last;
	ft_putchar(a);
	while (i < x - 2)
	{
		ft_putchar(b);
		x--;
	}
	if (x > 1)
		ft_putchar(c);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		return ;
	if (y == 1)
		rushtop(x, 'A', 'B', 'C');
	else if (y <= 2)
	{
		rushtop(x, 'A', 'B', 'C');
		ft_rushbot(x, 'A', 'B', 'C');
	}
	else
	{
		rushtop(x, 'A', 'B', 'C');
		rushmid(x, y - 2, 'B');
		ft_rushbot(x, 'A', 'B', 'C');
	}
}
