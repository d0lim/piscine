/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 19:12:12 by dolim             #+#    #+#             */
/*   Updated: 2018/08/02 22:23:34 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_counter(int argc, char **argv)
{
	int		k;
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (--argc > 0)
	{
		k = 0;
		while (*argv[i] != '\0')
		{
			k++;
			count++;
			argv[i] -= k;
			*argv[i] = *(argv[i]) + 1;
		}
		count++;
		i++;
	}
	return (count);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		count;
	char	*str;
	int		i;
	int		j;

	count = ft_counter(argc, argv);
	str = (char*)malloc(sizeof(char) * count);
	i = 0;
	while (*argv != '\0')
	{
		j = 0;
		while (*argv[j] != '\0')
		{
			*(str++) = *argv[j++];
			i++;
		}
		*(str++) = '\n';
		argv++;
	}
	*(--str) = '\0';
	return (str - i);
}
