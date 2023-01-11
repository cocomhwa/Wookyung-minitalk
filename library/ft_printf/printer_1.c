/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooshin <wooshin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:13:02 by wooshin           #+#    #+#             */
/*   Updated: 2022/12/28 11:41:47 by wooshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_count(int c)
{
	ft_putchar(c);
	return (1);
}

int	ft_putstr_count(char *s)
{
	int	len;

	if (s == 0)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_strleng(s);
	ft_putstr(s);
	return (len);
}

int	ft_putptr_count(void *ptr)
{
	int				len;
	unsigned long	p;

	len = 0;
	p = (unsigned long)ptr;
	ft_putstr("0x");
	if (ptr == 0)
	{
		ft_putchar('0');
		return (3);
	}
	put_ptr(p);
	while (p != 0)
	{
		len++;
		p = p / 16;
	}
	return (len + 2);
}

int	ft_puthex_count(unsigned int num, const char c)
{
	int	len;

	len = 0;
	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	put_hex(num, c);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_putnbr_count(int num)
{
	int	len;

	len = 0;
	ft_putnbr(num);
	if (num < 0)
		len++;
	if (num == 0)
		return (1);
	else
	{
		while (num != 0)
		{
			len++;
			num = num / 10;
		}
	}
	return (len);
}
