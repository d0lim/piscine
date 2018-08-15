/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbixby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 11:37:23 by brbixby           #+#    #+#             */
/*   Updated: 2018/08/12 19:19:52 by brbixby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);
int		ft_atoi(char *str);

int		main(int argc, char **argv)
{
	if (argc >= 3)
		rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	else
		write(1, "aucune\n", 7);
	return (0);
}
