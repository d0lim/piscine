/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 20:39:16 by dolim             #+#    #+#             */
/*   Updated: 2018/07/31 21:35:59 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_putstr(argv[0]);
		ft_putchar('\n');
		return (0);
	}
	ft_putstr(argv[0]);
	ft_putchar('\n');
	return (0);
}
