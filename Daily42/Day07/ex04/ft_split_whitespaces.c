/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 20:33:42 by dolim             #+#    #+#             */
/*   Updated: 2018/08/02 22:24:33 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_counter(char *str)
{
	int		count;
	int		j;

	count = 0;
	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == '\n' || str[j] == '\t' || str[j] == ' ')
			if (!(str[j + 1] == '\n' || str[j + 1] == '\t' || str[j + 1] == ' '))  
				count++;
		j++;
	}
	return (count);
}

void	ft_arr(int *carr, int count, char *str)
{
	int		j;

	j = 0;
	while (str[j] != '\0')
	{
		if (!(str[j] == '\n' || str[j] == '\t' || str[j] == ' '))	
			(*carr)++;
		else if (str[j] == '\n' || str[j] == '\t' || str[j] == ' ')
			if (!(str[j + 1] == '\n' || str[j + 1] == '\t' || str[j + 1] == ' '))
				carr++;
	}
	carr -= count;
}

void	ft_cpy(char **res, char *str, int count)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (j < count)
	{
		while (!(str[i] == '\n' || str[i] == '\t' || str[i] == ' '))
			*(res[j]++) = str[i++];
		*res[j++] = '\0';
		i++;
	}
	*res[j] = '\0';
}

char	**ft_split_whitespaces(char *str)
{
	char	**res;
	int		count;
	int		j;
	int		*carr;

	j = 0;
	count = ft_counter(str);
	count++;
	res = (char**)malloc(sizeof(char*) * (count + 1));
	carr = (int*)malloc(sizeof(int) * count);
	ft_arr(carr, count, str);
	while (j < count)
	{
		res[j] = (char*)malloc(sizeof(char) * (*carr + 1));
		j++;
		carr++;
	}
	carr -= count;
	ft_cpy(res, str, count);
	return (res);
}
