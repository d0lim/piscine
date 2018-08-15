/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 20:38:21 by dolim             #+#    #+#             */
/*   Updated: 2018/07/28 22:08:19 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_color_hv(int flag[8][8])
{
	int		j;
	int		row;
	int		col;

	j = 0;
	while (j++ < 64)
	{
		row = 0;
		col = 0;
		if (flag[j / 8][j % 8] == 0)
		{
			row = j / 8;
			while (col++ < 8)
				flag[row][col] = 1;
			row = 0;
			col = j % 8;
			while (row++ < 8)
				flag[row][col] = 1;
			break ;
		}
	}
}

void	ft_color_x(int flag[8][8])
{
	int		j;
	int		row;
	int		col;

	j = 0;
	while (j++ < 64)
	{
		if (flag[j / 8][j % 8] == 0)
		{
			row = j / 8;
			col = j % 8;
			while (row-- >= 0 && col-- >= 0)
				flag[row][col] = 1;
			while (row-- >= 0 && col++ < 8)
				flag[row][col] = 1;
			while (row++ < 8 && col++ < 8)
				flag[row][col] = 1;
			while (row++ < 8 && col-- >= 0)
				flag[row][col] = 1;
			break ;
		}
	}
}

int		ft_eight_queens_puzzle(void)
{
	int		flag[8][8];
	int		i;
	int		j;
	int		rt;
	int		tmp;

	i = 0;
	while (i++ < 64)
		flag[i / 8][i % 8] = 0;
	i = 0;
	rt = 1;
	while (i++ < 8)
	{
		j = 0;
		tmp = 0;
		while (j++ < 64)
		{
			if (flag[j / 8][j % 8] == 0)
				tmp++;
		}
		ft_color_hv(flag);
		ft_color_x(flag);
		rt *= tmp;
	}
	return (rt);
}
