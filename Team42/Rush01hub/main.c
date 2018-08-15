/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 10:28:20 by cschulle          #+#    #+#             */
/*   Updated: 2018/08/05 21:17:14 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int    sudoku(void);
int    chartoint(int p, int q, char **argv);
int ft_putchar(char c);
int    sudoku_2(void);
int    preprocess(void);
int        mapcompare(void);

int    g_map[9][9];
int    g_map_2[9][9];
int    g_flag;
int    g_antiflag;

int ft_input(int argc, char **argv)
{
    int i;
    int j;
    
    if (argc != 10)
    {
        printf("Error\n");
        return (10);
    }
    i = 1;
    while (i < argc)
    {
        j = 0;
        while (j < 9)
        {
            g_map[i - 1][j] = chartoint(i, j, argv);
            g_map_2[i - 1][j] = chartoint(i, j, argv);
            j++;
        }
        i++;
    }
    if (preprocess() == -1)
    {
        printf("Error\n");
        return (11);
    }
    return (0);
}

void print_result(void)
{
    int i;
    int j;

    i = 0;
    while (i < 9)
    {
        j = 0;
        while (j < 9)
        {
            ft_putchar(g_map[i][j] + 48);
            ft_putchar(' ');
            j++;
        }
        i++;
        write(1, "\n", 1);
        
    }
}

int    main(int argc, char **argv)
{
    int input;
    
    g_flag = 0;
    input = ft_input(argc, argv);
    if (input == 10)
        return (0);
    else if (input == 11)
        return (0);
    sudoku();
    sudoku_2();
    if (!mapcompare())
    {
        printf("Error\n");
        return (0);
    }
    else if (g_flag == 0 && g_antiflag == 0)
    {
        printf("Error\n");
        return (0);
    }
    print_result();
    return (0);
}

int chartoint(int p, int q, char **argv)
{
    if (argv[p][q] >= '0' && argv[p][q] <= '9')
        return (argv[p][q] - 48);
    if (argv[p][q] == '.')
        return (0);
    return (0);
}

int		mapcompare(void)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{	
			if (g_map[i][j] != g_map_2[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}