/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <dolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 01:06:22 by dolim             #+#    #+#             */
/*   Updated: 2018/08/09 21:15:20 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	print_file(char *name)
{
	int		fd;
	char	buf[1];

	fd = open(name, O_RDONLY);
	while (read(fd, buf, sizeof(buf)))
	{
		write(1, buf, sizeof(buf));
	}
	close(fd);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		print_file(argv[1]);
	else if (argc < 2)
		write(2, "File name missing.\n", 19);
	else
		write(2, "Too many arguments.\n", 20);
	return (0);
}
