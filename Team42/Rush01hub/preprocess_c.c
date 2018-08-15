/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errchk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 17:42:24 by dolim             #+#    #+#             */
/*   Updated: 2018/08/05 23:25:03 by kachen2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		p_check(int x, int y, int z);
int		p_box(int x, int y, int z);

int		g_map[9][9];

int		preprocess(void)
{
	int		x;
	int		y;

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			if (g_map[x][y] != 0 && !p_check(x, y, g_map[x][y]))
				return (-1);
			y++;
		}
		x++;
	}
	return (0);
}

int		p_check(int x, int y, int z)
{
	int j;
	int a;
	int b;
	int i;

	i = 0;
	j = -1;
	a = 0;
	b = 0;
	while (++j < 9)
	{
		if (j != y)
			if (g_map[x][j] == z)
				return (0);
	}
	j = -1;
	while (++j < 9)
	{
		if (j != x)
			if (g_map[j][y] == z)
				return (0);
	}
	if (p_box(x, y, z) == 2)
		return (0);
	return (1);
}

int		p_box(int x, int y, int z)
{
	int i;
	int a;
	int b;
	int j;

	i = 0;
	j = 0;
	a = 0;
	b = 0;
	a = (x / 3) * 3;
	b = (y / 3) * 3;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if ((a + i) != x && (b + j) != y)
				if (g_map[a + i][b + j] == z)
					return (2);
			j++;
		}
		i++;
	}
	return (1);
}
