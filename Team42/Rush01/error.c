/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 14:35:52 by dolim             #+#    #+#             */
/*   Updated: 2018/08/05 17:34:18 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		error(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	
	if (argc != 10)
		return (-1);
	i = 0;
	j = 0;
	k = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (!(argv[i + 1][j] >= '0' && argv[i + 1][j] <= '9')
					&& argv[i + 1][j] != '.')
				return (-1);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			k = 1;
			while (argv[i + 1 + k][j] != '\0')
			{
				if (argv[i + 1][j] == argv[i + 1 + k][j])
					return (-1);
				k++;
			}
		}
	}
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			k = 1;
			while (argv[i + 1][j + k] != '\0')
			{
				if (argv[i + 1][j] == argv[i + 1][j + k])
					return (-1);
				k++;
			}
		}
	}
	


