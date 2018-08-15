/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <dolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 11:08:56 by brbixby           #+#    #+#             */
/*   Updated: 2018/08/12 18:25:16 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "colle_3.h"

t_return	*ft_rush34(int i, char *str, t_return *rt)
{
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			rt->row++;
		else if (ch_err(str[i], 'A', 'B', 'C'))
			return (0);
		i++;
	}
	if (str[i - 2] == 'C')
		rt->rush = 3;
	else if (str[i - 2] == 'A')
		rt->rush = 4;
	return (rt);
}

t_return	*ft_aa(int i, char *str, t_return *rt)
{
	while (str[i] != '\n')
	{
		if (ch_err(str[i], 'A', 'B', 'C'))
			return (0);
		rt->column++;
		i++;
	}
	rt->row++;
	if (str[(++i) - 2] == 'A')
		rt = ft_rush02(i, str, rt);
	else if (str[i - 2] == 'C')
		rt = ft_rush34(i, str, rt);
	else
	{
		ft_putstr("aucune\n");
		return (0);
	}
	return (rt);
}

t_return	*ft_which(char *str, t_return *rt)
{
	int			i;

	i = 0;
	if (str[i] == 'o')
	{
		rt = ft_rush00(str, rt);
		return (rt);
	}
	else if (str[i] == '/')
	{
		rt = ft_rush01(str, rt);
		return (rt);
	}
	else if (str[i] == 'A')
		if (!(rt = ft_aa(i, str, rt)))
			return (0);
		else
			return (rt);
	else
	{
		ft_putstr("aucune\n");
		return (0);
	}
}

void		ft_print_result(t_return *rt)
{
	if (rt->column == 1 && rt->row == 1 && (rt->rush >= 2 && rt->rush <= 4))
	{
		ft_putstr("[colle-02] [1] [1] || [colle-03] [1] [1] ");
		ft_putstr("|| [colle-04] [1] [1]\n");
	}
	else if ((rt->rush == 2 || rt->rush == 4) && rt->column == 1)
	{
		ft_putstr("[colle-02] [1] [");
		ft_putnbr(rt->row);
		ft_putstr("] || [colle-04] [1] [");
		ft_putnbr(rt->row);
		ft_putstr("]\n");
	}
	else if ((rt->rush == 3 || rt->rush == 4) && rt->row == 1)
	{
		ft_putstr("[colle-03] [");
		ft_putnbr(rt->column);
		ft_putstr("] [1] || [colle-04] [");
		ft_putnbr(rt->column);
		ft_putstr("] [1]\n");
	}
	else
		ft_print_default(rt);
}

int			main(void)
{
	char		buf[1];
	char		*str;
	int			i;
	t_return	*rt;

	rt = (t_return *)malloc(sizeof(t_return));
	rt->row = 0;
	rt->column = 0;
	str = (char*)malloc(sizeof(char) * 999999);
	i = 0;
	while (read(0, buf, 1))
		str[i++] = *buf;
	str[i] = '\0';
	if (str[0] == '\0')
	{
		rt->rush = -1;
		ft_print_default(rt);
		return (0);
	}
	rt = ft_which(str, rt);
	if (rt == 0)
		return (0);
	ft_print_result(rt);
	return (0);
}
