/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 20:58:48 by dolim             #+#    #+#             */
/*   Updated: 2018/07/31 21:49:59 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1++ == *s2++)
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
	return (*(s1 - 1) - *(s2 - 1));
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

char	*ft_strcpy(char *dest, char *src)
{
	int		count;

	count = 0;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		count++;
	}
	*dest = '\0';
	dest -= count;
	return (dest);
}

void	ft_sort(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	j = 1;
	temp = 0;
	while (i < argc)
	{
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				ft_strcpy(temp, argv[i]);
				ft_strcpy(argv[i], argv[j]);
				ft_strcpy(argv[j], temp);
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	if (argc == 1)
		return (0);
	i = 1;
	ft_sort(argc, argv);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
	}
	return (0);
}
