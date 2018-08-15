/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 18:27:59 by dolim             #+#    #+#             */
/*   Updated: 2018/08/05 23:17:04 by kachen2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		sudoku(void);
int		check(int x, int y, int z);
int		cbox(int x, int y, int z);
int		recursive(int i, int j);

int		g_map[9][9];
int		g_flag;

int		sudoku(void)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (g_map[i][j] == 0)
			{
				if (recursive(i, j) == 5)
					return (0);
				return (0);
			}
			j++;
		}
		i++;
	}
	g_flag++;
	return (0);
}

int		recursive(int i, int j)
{
	int z;

	z = 1;
	while (z <= 9)
	{
		if (check(i, j, z) == 1)
		{
			g_map[i][j] = z;
			sudoku();
			if (g_flag >= 1)
				return (5);
			g_map[i][j] = 0;
		}
		z++;
	}
	return (1);
}

int		check(int x, int y, int z)
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
		if (g_map[x][j] == z)
			return (0);
		j++;
	}
	j = 0;
	while (j < 9)
	{
		if (g_map[j][y] == z)
			return (0);
		j++;
	}
	if (cbox(x, y, z) == 2)
		return (0);
	return (1);
}

int		cbox(int x, int y, int z)
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
			if (g_map[a + i][b + j] == z)
				return (2);
			j++;
		}
		i++;
	}
	return (1);
}
