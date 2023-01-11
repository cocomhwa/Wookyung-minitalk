/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooshin <wooshin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:02:59 by wooshin           #+#    #+#             */
/*   Updated: 2022/12/14 05:01:10 by wooshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int num)
{
	long	inputnumb;
	int		devidenumb;
	char	numb;

	inputnumb = num;
	if (!num)
	{
		write(1, "0", 1);
		return ;
	}
	if (num < 0)
	{
		write(1, "-", 1);
		inputnumb *= -1;
	}
	devidenumb = 1000000000;
	while (devidenumb > inputnumb)
		devidenumb /= 10;
	while (devidenumb)
	{
		numb = inputnumb / devidenumb + '0';
		inputnumb %= devidenumb;
		devidenumb /= 10;
		write(1, &numb, 1);
	}
}

int	put_unsigned(unsigned int num)
{
	const char	base[10] = "0123456789";

	if (num >= 10)
	{
		put_unsigned(num / 10);
		put_unsigned(num % 10);
	}
	else
		write(1, &base[num], 1);
	return (0);
}
