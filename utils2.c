/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooshin <wooshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:41:50 by wooshin           #+#    #+#             */
/*   Updated: 2023/01/12 21:10:24 by wooshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	double_check(char *str)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = ft_strlen(str) - 1;
	while (i <= size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	useable(char idx, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (idx == base[i])
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

static int	check_base(char *base)
{
	int	i;

	i = 0;
	if (base[0] == '\0' || ft_strlen(base) == 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-'
			|| ((base[i] >= 9 && base[i] <= 13) || base[i] == 32))
			return (0);
		else if (double_check(base))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	if (!check_base(base))
		return (0);
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i] != '\0')
		i++;
	while ((str[i] == 43 || str[i] == 45) && str[i] != '\0')
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && (useable(str[i], base) != -1))
	{
		result *= ft_strlen(base);
		result += useable(str[i], base);
		i++;
	}
	return (result * sign);
}
