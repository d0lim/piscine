/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <dolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 02:43:36 by dolim             #+#    #+#             */
/*   Updated: 2018/08/09 21:16:08 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int		ft_strcmp(char *s1, char *s2);
void	ft_putchar2(char c);
void	ft_puterror(char *file, char *str);

void	input(void)
{
	char	buf[1];

	while (read(0, buf, sizeof(buf)))
		write(1, buf, sizeof(buf));
}

int		print_file(char *name)
{
	int		fd;
	char	buf[1];

	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (errno);
	while (read(fd, buf, sizeof(buf)))
	{
		write(1, buf, sizeof(buf));
	}
	close(fd);
	return (0);
}

void	show_error(char *name)
{
	int		n;

	if (!ft_strcmp(name, "-"))
		input();
	else
	{
		n = print_file(name);
		if (n == 2)
			ft_puterror(name, "No such file or directory");
		else if (n == 13)
			ft_puterror(name, "Permission denied");
		else if (n == 21)
			ft_puterror(name, "Is a directory");
	}
}

int		main(int argc, char **argv)
{
	if (argc <= 1)
		input();
	else
		while (argc-- > 1)
			show_error(argv[argc]);
	return (0);
}
