/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <dolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 11:40:59 by dolim             #+#    #+#             */
/*   Updated: 2018/08/12 14:02:52 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct	s_return
{
	int		rush;
	int		row;
	int		column;
}				t_return;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(str);
		str++;
	}
}

t_return	*ft_which(char *str)
{
	int			i;
	t_return	*rt;

	rt = (t_return *)malloc(sizeof(t_return));
	i = 0;
	rt->row = 0;
	rt->column = 0;
	if (str[i] == 'o')
	{
		rt->rush = 0;
		while (str[i] != '\n')
		{
			if (!(str[i] == 'o' || str[i] == '-'))
			{
				ft_putstr("Error!\n");
				return (0);
			}
			rt->column++;
			i++;
		}
		i++;
		rt->row++;
		while (str[i] != '\0')
		{

			if (str[i] = '\n')
				rt->row++;
			else if (!(str[i] == 'o' || str[i] == '-' || str[i] == '|'))
			{
				ft_putstr("Error!\n");
				return (0);
			}
			i++;
		}
		return (rt);
	}
	else if (str[i] == '/')
	{
		rt->rush = 1;
		while (str[i] != '\n')
		{
			if (!(str[i] == '/' || str[i] == '*' || str[i] == '\\'))
			{
				ft_putstr("Error!\n");
				return (0);
			}
			rt->column++;
			i++;
		}
		i++;
		rt->row++;
		while (str[i] != '\0')
		{

			if (str[i] = '\n')
				rt->row++;
			else if (!(str[i] == '/' || str[i] == '*' || str[i] == '\\'))
			{
				ft_putstr("Error!\n");
				return (0);
			}
			i++;
		}
		return (rt);
	}
	else if (str[i] == 'A')
	{
		while (str[i] != '\n')
		{
			if (!(str[i] == 'A' || str[i] == 'B' || str[i] == 'C'))
			{
				ft_putstr("Error!\n");
				return (0);
			}
			rt->column++;
			i++;
		}
		i++;
		rt->row++;
		if (str[i - 2] == 'A')
		{
			rt->rush = 2;
			while (str[i] != '\0')
			{
				if (str[i] = '\n')
					rt->row++;
				else if (!(str[i] == 'A' || str[i] == 'B' || str[i] == 'C'))
				{
					ft_putstr("Error!\n");
					return (0);
				}
				i++;
			}
			return (rt);
		}
		else if (str[i - 2] == 'C')
		{
			while (str[i] != '\0')
			{
				if (str[i] = '\n')
					rt->row++;
				else if (!(str[i] == 'A' || str[i] == 'B' || str[i] == 'C'))
				{
					ft_putstr("Error!\n");
					return (0);
				}
				i++;
			}
			if (str[i - 2] == 'C')
				rt->rush = 3;
			else if (str[i - 2] == 'A')
				rt->rush = 4;
			return (rt);
		}
		else
		{
			ft_putstr("Error\n");
			return (0);
		}
	}
	ft_putstr("Error\n");
	return (0);
}