/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <dolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 03:59:08 by dolim             #+#    #+#             */
/*   Updated: 2018/08/09 21:16:32 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putchar2(char c)
{
	write(2, &c, 1);
}

void	ft_puterror(char *file, char *str)
{
	write(2, "cat : ", 5);
	while (*file != '\0')
	{
		ft_putchar2(*file);
		file++;
	}
	ft_putchar2(':');
	ft_putchar2(' ');
	while (*str != '\0')
	{
		ft_putchar2(*str);
		str++;
	}
	ft_putchar2('\n');
}
