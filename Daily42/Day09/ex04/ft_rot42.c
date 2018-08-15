/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:35:28 by dolim             #+#    #+#             */
/*   Updated: 2018/08/03 16:35:30 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	rotate_up(char c)
{
	c = c - 65;
	c = ((c + 42) % 26);
	c = c + 65;
	return (c);
}

char	rotate_low(char c)
{
	c = c - 97;
	c = ((c + 42) % 26);
	c = c + 97;
	return (c);
}

char	rotate(char c)
{
	if (c >= 65 && c <= 90)
		return (rotate_up(c));
	else if (c >= 97 && c <= 122)
		return (rotate_low(c));
	else
		return (c);
}

char	*ft_rot42(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = rotate(str[i]);
		i++;
	}
	return (str);
}
