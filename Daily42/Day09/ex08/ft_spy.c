/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:35:55 by dolim             #+#    #+#             */
/*   Updated: 2018/08/03 16:35:56 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_alert(void)
{
	write(1, "Alert!!!\n", 9);
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	find_alert(char *str)
{
	if (ft_strcmp(str, "president") == 0)
		ft_alert();
	if (ft_strcmp(str, "attack") == 0)
		ft_alert();
	if (ft_strcmp(str, "Bauer") == 0)
		ft_alert();
}

void	min(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	char	temp[1000];
	int		i;
	int		j;
	int		k;

	i = 1;
	while (i < argc)
	{
		j = 0;
		k = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
			{
				temp[k++] = argv[i][j];
			}
			j++;
		}
		temp[j] = '\0';
		min(temp);
		find_alert(temp);
		i++;
	}
	return (0);
}
