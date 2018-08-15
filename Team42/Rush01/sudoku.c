/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 18:27:59 by dolim             #+#    #+#             */
/*   Updated: 2018/08/05 14:35:30 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		sudoku(void);
int		check(int x, int y, int z);
int		box(int x, int y, int z);

int		g_map[9][9];
int		g_flag;

int		main(void)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	printf("Input started\n\n");
	for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            scanf("%d", &g_map[i][j]);
        }
    }
	printf("Input is done!\n");
	sudoku();
	printf("\n\nResult\n\n");
	i = 0;
	while (i < 9)
	{   
	    j = 0;
		while (j < 9)
		{
			printf("%d ", g_map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");
	return (0);
}

int		sudoku(void)
{
    int i;
    int j;
    int z;
    
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (g_map[i][j] == 0)
			{
				z = 1;
				while (z <= 9)
				{
					if (check(i, j, z) == 1)
					{
						g_map[i][j] = z;
						sudoku();
						if (g_flag == 1)
							return (0);
						g_map[i][j] = 0;
					}
					z++;
				}
				return (0);
			}
			j++;
		}
		i++;
	}
	g_flag = 1;
	return (0);
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
	if (box(x, y, z) == 2)
		return (0);
	return (1);
}

int		box(int x, int y, int z)
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
