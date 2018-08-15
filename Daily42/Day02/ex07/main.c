/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 14:28:55 by dolim             #+#    #+#             */
/*   Updated: 2018/07/26 17:42:07 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}
	
void ft_print(long num, int n)
{
	int i;
	unsigned long ex;
	ex = 1;
	i = 0;
	while(i < n)
	{
		ex = ex * 10;
		i = i + 1;
	}
	i = 0;
	while(i < n)
	{	
		ft_putchar((num%(ex*10)/ex) + 48);
		i = i + 1;
	}
}

int ft_checker(long num, int n)
{
	unsigned long ex;
	int i;
	ex = 1;
	i = 0;
	while(i < n)
	{
		if((num % (ex * 10)) / ex >= (num % ex))
		{
			return (1);
		}
		ex = ex * 10;
		i = i + 1;		
	}
	return (0);
}

void ft_print_combn(int n)
{
	int i;
	int j;
	int k;
	long num;
	long ex;
	ex = 1;
	num = 1;
	i = 0;
	while(i < n)
	{
		ex = ex * 10;
		i = i + 1;
	}
	while(num < ex)
	{
		if(ft_checker(num, n) == 0)
				ft_print(num, n);
		num = num + 1;
	}
}

int main(void)
{
	ft_print_combn(4);
	return (0);
}
