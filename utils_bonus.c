/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooshin <wooshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:40:26 by wooshin           #+#    #+#             */
/*   Updated: 2023/01/14 01:02:45 by wooshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	checkspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 0;
	result = 0;
	while (checkspace(str[i]) && str[i] != 0)
		i++;
	if ((str[i] == 43 || str[i] == 45) && str[i] != 0)
	{
		if (str[i] == 45)
			sign = !sign;
		i++;
	}
	while (str[i] != 0 && (str[i] >= 48 && str[i] <= 57))
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	if (sign)
		return (-result);
	return (result);
}
