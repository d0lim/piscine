/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <dolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 11:06:27 by brbixby           #+#    #+#             */
/*   Updated: 2018/08/12 18:00:06 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLE_3_H
# define COLLE_3_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_return
{
	int			rush;
	int			row;
	int			column;
}				t_return;

int				ch_err(char str, char a, char b, char c);
t_return		*ft_rush00(char *str, t_return *rt);
t_return		*ft_rush01(char *str, t_return *rt);
t_return		*ft_rush02(int i, char *str, t_return *rt);
t_return		*ft_rush34(int i, char *str, t_return *rt);
t_return		*ft_aa(int i, char *str, t_return *rt);
t_return		*ft_which(char *str, t_return *rt);
void			ft_print_default(t_return *rt);

#endif
