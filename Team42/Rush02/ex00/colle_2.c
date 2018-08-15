/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <dolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 11:08:56 by brbixby           #+#    #+#             */
/*   Updated: 2018/08/12 18:25:17 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "colle_3.h"

int			ch_err(char str, char a, char b, char c)
{
	if (!(str == a || str == b || str == c || str == ' '))
	{
		ft_putstr("aucune\n");
		return (1);
	}
	return (0);
}

t_return	*ft_rush00(char *str, t_return *rt)
{
	int		i;

	i = 0;
	rt->rush = 0;
	while (str[i] != '\n')
	{
		if (ch_err(str[i], 'o', '-', 'o'))
			return (0);
		rt->column++;
		i++;
	}
	rt->row++;
	while (str[++i] != '\0')
	{
		if (str[i] == '\n')
			rt->row++;
		else if (ch_err(str[i], 'o', '-', '|'))
			return (0);
	}
	return (rt);
}

t_return	*ft_rush01(char *str, t_return *rt)
{
	int		i;

	i = 0;
	rt->rush = 1;
	while (str[i] != '\n')
	{
		if (ch_err(str[i], '/', '*', '\\'))
			return (0);
		rt->column++;
		i++;
	}
	rt->row++;
	while (str[++i] != '\0')
	{
		if (str[i] == '\n')
			rt->row++;
		else if (ch_err(str[i], '/', '*', '\\'))
			return (0);
	}
	return (rt);
}

t_return	*ft_rush02(int i, char *str, t_return *rt)
{
	rt->rush = 2;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			rt->row++;
		else if (ch_err(str[i], 'A', 'B', 'C'))
			return (0);
		i++;
	}
	return (rt);
}

void		ft_print_default(t_return *rt)
{
	if (rt->rush == -1)
	{
		ft_putstr("[colle-00] [0] [0] || [colle-01] [0] [0] ");
		ft_putstr("|| [colle-02] [0] [0] || [colle-03] [0] [0] ");
		ft_putstr("|| [colle-04] [0] [0]\n");
	}
	else
	{
		ft_putstr("[rush-0");
		ft_putnbr(rt->rush);
		ft_putstr("] [");
		ft_putnbr(rt->column);
		ft_putstr("] [");
		ft_putnbr(rt->row);
		ft_putstr("]\n");
	}
}
