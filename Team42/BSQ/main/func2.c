/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <dolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 02:01:32 by dolim             #+#    #+#             */
/*   Updated: 2018/08/15 02:23:03 by lyoung-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		buf_check(char ***qst, char buf, t_lc *lc, t_ij *ij)
{
	if (buf != '\n')
	{
		(*qst)[ij->i][ij->j] = buf;
		(ij->j)++;
		if ((ij->j) > lc->column)
			return (1);
	}
	else if (buf == '\n')
	{
		if (ij->j != lc->column)
			return (1);
		(ij->i)++;
		ij->j = 0;
	}
	return (0);
}

t_lc	*get_file(char *name, char ***qst)
{
	int		fd;
	char	buf[1];
	t_lc	*lc;
	t_ij	*ij;

	ij = (t_ij *)malloc(sizeof(t_ij));
	lc = get_info(name, qst);
	fd = open(name, O_RDONLY);
	ij->i = 0;
	ij->j = 0;
	while (read(fd, buf, sizeof(buf)))
		if (*buf == '\n')
			break ;
	while (read(fd, buf, sizeof(buf)))
	{
		if (buf_check(qst, *buf, lc, ij))
			break ;
	}
	close(fd);
	return (lc);
}

int		ft_min(int a, int b, int c)
{
	a = a < b ? a : b;
	return (a < c ? a : c);
}

void	solve_mark(char ***solved, t_lc *lc, t_loop *lp)
{
	int		n;
	int		a;
	int		b;

	n = 0;
	a = lp->i - 1;
	while (lp->m < lp->max)
	{
		b = lp->j - 1;
		n = 0;
		while (n < lp->max)
		{
			(*solved)[a][b] = lc->info[2];
			b--;
			n++;
		}
		a--;
		lp->m++;
	}
}

void	solve_draw(int **grid, char ***solved, t_lc *lc, t_loop *lp)
{
	lp->j = 1;
	while (lp->j <= lc->column)
	{
		if (grid[lp->i][lp->j] >= 2 && grid[lp->i][lp->j] <= lp->max)
			(*solved)[lp->i - 1][lp->j - 1] = lc->info[0];
		if (grid[lp->i][lp->j] == lp->max)
			solve_mark(solved, lc, lp);
		else if (grid[lp->i][lp->j] == 0)
			(*solved)[lp->i - 1][lp->j - 1] = lc->info[1];
		if (grid[lp->i][lp->j] == 1)
			(*solved)[lp->i - 1][lp->j - 1] = lc->info[0];
		lp->j++;
	}
	lp->i++;
}
