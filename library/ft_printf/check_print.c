/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooshin <wooshin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:06:57 by wooshin           #+#    #+#             */
/*   Updated: 2022/12/14 03:28:48 by wooshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_print(const char c, va_list *ap)
{
	if (c == 'c')
		return (ft_putchar_count(va_arg(*ap, int)));
	else if (c == 's')
		return (ft_putstr_count(va_arg(*ap, char *)));
	else if (c == 'p')
		return (ft_putptr_count(va_arg(*ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_count(va_arg(*ap, int)));
	else if (c == 'u')
		return (ft_un_putnbr_count(va_arg(*ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex_count(va_arg(*ap, unsigned int), c));
	else if (c == '%')
		return (ft_putchar_count('%'));
	return (0);
}
