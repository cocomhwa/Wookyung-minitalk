/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooshin <wooshin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:22:19 by wooshin           #+#    #+#             */
/*   Updated: 2022/12/28 11:40:13 by wooshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strleng(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strleng(s));
}

int	put_ptr(unsigned long p)
{
	const char	base[16] = "0123456789abcdef";

	if (p >= 16)
	{
		put_ptr(p / 16);
		put_ptr(p % 16);
	}
	else
		write(1, &base[p], 1);
	return (0);
}

int	put_hex(unsigned int num, const char c)
{
	const char	base_lower[16] = "0123456789abcdef";
	const char	base_upper[16] = "0123456789ABCDEF";

	if (num >= 16)
	{
		put_hex(num / 16, c);
		put_hex(num % 16, c);
	}
	else
	{
		if (c == 'x')
			write(1, &base_lower[num], 1);
		if (c == 'X')
			write(1, &base_upper[num], 1);
	}
	return (0);
}
