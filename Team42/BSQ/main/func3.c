/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <dolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 02:02:27 by dolim             #+#    #+#             */
/*   Updated: 2018/08/15 03:37:00 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	solve_alloc(char ***solved, t_lc *lc)
{
	int i;

	*solved = (char **)malloc(sizeof(char *) * lc->line);
	i = 0;
	while (i < lc->line)
	{
		(*solved)[i] = (char *)malloc(sizeof(char) * lc->column);
		i++;
	}
}

void	solve_print(int **grid, int max, t_lc *lc)
{
	char	**solved;
	t_loop	*lp;

	solve_alloc(&solved, lc);
	lp = (t_loop *)malloc(sizeof(t_loop));
	lp->max = max;
	lp->i = 1;
	lp->m = 0;
	while (lp->i <= lc->line)
		solve_draw(grid, &solved, lc, lp);
	lp->i = 0;
	while (lp->i < lc->line)
	{
		lp->j = 0;
		while (lp->j < lc->column)
		{
			write(1, &solved[lp->i][lp->j], 1);
			lp->j++;
		}
		write(1, "\n", 1);
		lp->i++;
	}
}

void	input_data(char ***qst, t_lc *lc)
{
	char	buf[1];
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (read(0, buf, sizeof(buf)) && i < lc->line)
	{
		if (*buf != '\n')
		{
			(*qst)[i][j] = *buf;
			j++;
			if (j > lc->column)
				break ;
		}
		else if (*buf == '\n')
		{
			if (j != lc->column)
				break ;
			i++;
			if (i == lc->line)
				break ;
			j = 0;
		}
	}
}

void	column_realloc(char ***qst, t_lc *lc)
{
	char	buf[1];
	int		i;

	i = 0;
	while (read(0, buf, sizeof(buf)))
	{
		if (*buf != '\n')
		{
			lc->column++;
			(*qst)[0] = recalloc((*qst)[0], sizeof(char) * (lc->column + 1));
			(*qst)[0][i] = *buf;
			(*qst)[0][i + 1] = 0;
			i++;
		}
		else
			break ;
	}
}

t_lc	*input(char ***qst)
{
	char	buf[1];
	t_lc	*lc;
	int		i;
	char	*info_string;

	info_string = (char *)malloc(sizeof(char));
	info_string[0] = 0;
	lc = (t_lc *)malloc(sizeof(t_lc));
	lc->line = 0;
	while (read(0, buf, sizeof(buf)))
		if (info_line(*buf, &info_string))
			break ;
	read_info(lc, info_string);
	*qst = (char **)malloc(sizeof(char *) * (lc->line));
	(*qst)[0] = (char *)malloc(sizeof(char));
	lc->column = 0;
	column_realloc(qst, lc);
	i = 1;
	while (i < lc->line)
	{
		(*qst)[i] = (char *)malloc(sizeof(char) * lc->column);
		i++;
	}
	input_data(qst, lc);
	return (lc);
}
