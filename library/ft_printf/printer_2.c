/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooshin <wooshin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:14:10 by wooshin           #+#    #+#             */
/*   Updated: 2022/12/14 04:06:48 by wooshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_un_putnbr_count(unsigned int num)
{
	int	len;

	len = 0;
	put_unsigned(num);
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
