/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:34:04 by dolim             #+#    #+#             */
/*   Updated: 2018/08/03 16:34:06 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_BOOLEAN_H
# define	FT_BOOLEAN_H

# include <unistd.h>

typedef	int	t_bool;

# define	TRUE	1
# define	FALSE	0
# define	EVEN(x)	((x % 2) == 0 ? TRUE : FALSE)
# define	SUCCESS	0
# define	EVEN_MSG	"I have an even number of arguments.\n"
# define	ODD_MSG		"I have an odd number of arguments.\n"

void		ft_putstr(char *str);
t_bool		ft_is_even(int nbr);

#endif
