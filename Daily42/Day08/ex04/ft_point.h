/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:34:17 by dolim             #+#    #+#             */
/*   Updated: 2018/08/03 16:34:20 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_POINT_H
# define	FT_POINT_H

typedef	struct	coordinate
{
	int x;
	int y;
}				t_point;

void			set_point(t_point *point);

#endif
