/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 17:20:35 by cschulle          #+#    #+#             */
/*   Updated: 2018/08/05 23:17:06 by kachen2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		anti_recursive(int i, int j);
int		g_map_2[9][9];
int		g_flag;
int		g_antiflag;
int		check(int x, int y, int z);
int		check2(int x, int y, int z);
int		cbox2(int x, int y, int z);

int		sudoku_2(void)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 8;
		while (j >= 0)
		{
			if (g_map_2[i][j] == 0)
			{
				if (anti_recursive(i, j) == 5)
					return (0);
				return (0);
			}
			j--;
		}
		i++;
	}
	g_flag++;
	g_antiflag = 1;
	return (0);
}

int		anti_recursive(int i, int j)
{
	int z;

	z = 1;
	while (z <= 9)
	{
		if (check2(i, j, z) == 1)
		{
			g_map_2[i][j] = z;
			sudoku_2();
			if (g_antiflag == 1)
				return (5);
			g_map_2[i][j] = 0;
		}
		z++;
	}
	return (1);
}

int		check2(int x, int y, int z)
{
	int j;
	int a;
	int b;
	int i;

	i = 0;
	j = 0;
	a = 0;
	b = 0;
	while (j < 9)
	{
		if (g_map_2[x][j] == z)
			return (0);
		j++;
	}
	j = 0;
	while (j < 9)
	{
		if (g_map_2[j][y] == z)
			return (0);
		j++;
	}
	if (cbox2(x, y, z) == 2)
		return (0);
	return (1);
}

int		cbox2(int x, int y, int z)
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
			if (g_map_2[a + i][b + j] == z)
				return (2);
			j++;
		}
		i++;
	}
	return (1);
}
