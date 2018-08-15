/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 03:50:56 by lyoung-j          #+#    #+#             */
/*   Updated: 2018/08/15 03:50:57 by lyoung-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strcpy(char *dest, char *src)
{
	char	*t;

	t = dest;
	while ((*t++ = *src++) != 0)
		;
	return (dest);
}

char	*recalloc(char *ptr, size_t size)
{
	char	*new;

	if (!ptr)
	{
		new = (char *)malloc(size);
	}
	else
	{
		new = (char *)malloc(size);
		ft_strcpy(new, ptr);
		free(ptr);
	}
	return (new);
}

int		info_line(char buf, char **info_string)
{
	if (buf == '\n')
		return (1);
	else
	{
		info_realloc(info_string, buf);
		return (0);
	}
}

int		column_count(char buf, t_lc *lc)
{
	if (buf == '\n')
		return (1);
	else
	{
		lc->column++;
		return (0);
	}
}

t_lc	*get_info(char *name, char ***qst)
{
	int		i;
	int		fd;
	char	buf[1];
	t_lc	*lc;
	char	*info_string;

	info_string = (char *)malloc(sizeof(char));
	info_string[0] = 0;
	lc = (t_lc *)malloc(sizeof(t_lc));
	fd = open(name, O_RDONLY);
	lc->line = 0;
	while (read(fd, buf, sizeof(buf)))
		if (info_line(*buf, &info_string))
			break ;
	read_info(lc, info_string);
	(*qst) = (char **)malloc(sizeof(char *) * (lc->line));
	lc->column = 0;
	while (read(fd, buf, sizeof(buf)))
		if (column_count(*buf, lc))
			break ;
	i = -1;
	while (++i < lc->line)
		(*qst)[i] = (char *)malloc(sizeof(char) * lc->column);
	close(fd);
	return (lc);
}
