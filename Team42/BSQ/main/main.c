/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <dolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 04:07:54 by dolim             #+#    #+#             */
/*   Updated: 2018/08/15 03:53:53 by lyoung-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int argc, char **argv)
{
	char	**qst;
	t_lc	*lc;
	int		k;

	qst = 0;
	lc = 0;
	k = 1;
	while (k < argc || argc == 1)
	{
		if (argc == 1)
		{
			lc = input(&qst);
			argc = 2;
			write(1, "\n", 1);
		}
		else
			lc = get_file(argv[k], &qst);
		if (k != 1)
			write(1, "\n", 1);
		after_input(lc, qst);
		free(qst);
		free(lc);
		k++;
	}
	return (0);
}

void	prb_sol(int **prb, int ***sol, t_lc *lc, int *max)
{
	int		i;
	int		j;

	i = 1;
	while (i < lc->line + 1)
	{
		j = 1;
		while (j < lc->column + 1)
		{
			if (prb[i][j] == 1)
			{
				(*sol)[i][j] = ft_min((*sol)[i - 1][j - 1],
				(*sol)[i - 1][j], (*sol)[i][j - 1]) + 1;
				*max = *max > (*sol)[i][j] ? *max : (*sol)[i][j];
			}
			j++;
		}
		i++;
	}
}

int		qst_prb(char **qst, int ***prb, t_lc *lc)
{
	int		i;
	int		j;

	i = 0;
	while (i < lc->line)
	{
		j = 0;
		while (j < lc->column)
		{
			if (qst[i][j] == lc->info[1])
				(*prb)[i + 1][j + 1] = 0;
			else if (qst[i][j] == lc->info[0])
				(*prb)[i + 1][j + 1] = 1;
			else
			{
				write(2, "map error\n", 10);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	alloc2arr(int ***arr, t_lc *lc)
{
	int		i;
	int		j;

	*arr = (int**)malloc(sizeof(int *) * (lc->line + 1));
	i = 0;
	while (i < lc->line + 1)
	{
		(*arr)[i] = (int *)malloc(sizeof(int) * (lc->column + 1));
		j = 0;
		while (j < lc->column + 1)
		{
			(*arr)[i][j] = 0;
			j++;
		}
		i++;
	}
}

int		after_input(t_lc *lc, char **qst)
{
	int		**prb;
	int		**sol;
	int		max;

	max = 0;
	if (lc->info[0] == lc->info[1] || lc->info[1] == lc->info[2]
	|| lc->info[0] == lc->info[2])
	{
		write(2, "map error\n", 10);
		return (1);
	}
	alloc2arr(&prb, lc);
	alloc2arr(&sol, lc);
	if (qst_prb(qst, &prb, lc))
		return (1);
	prb_sol(prb, &sol, lc, &max);
	solve_print(sol, max, lc);
	free(sol);
	free(prb);
	return (0);
}
