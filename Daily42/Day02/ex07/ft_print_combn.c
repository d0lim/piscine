/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 14:28:55 by dolim             #+#    #+#             */
/*   Updated: 2018/07/26 17:32:17 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_putchar(char c);

int ft_chercker(long num, int n)
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
	
void ft_print(long num, int n)
{
	int i;
	unsigned long ex;
	ex = 1;
	while(i < n)
		ex = ex * 10;
	while(i < n)
	{	
		ft_putchar((num%(ex*10)/ex) + 48);
	}
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
	while(i < n)
		ex = ex * 10;
	
	while(num < ex)
	{
		if(ft_checker(num, n == 0)
				ft_print(num, n);
	}
}
