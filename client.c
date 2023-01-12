/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooshin <wooshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:46:29 by wooshin           #+#    #+#             */
/*   Updated: 2023/01/12 18:54:56 by wooshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>

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

void	send_binary_signal(int pid, int bit, unsigned char c)
{
	while (bit > 0)
	{
		if (c % 2)
			kill(pid, SIGUSR1);
		else if (c % 2 == 0)
			kill(pid, SIGUSR2);
		c /= 2;
		bit--;
	}
}

int	main(int ac, char **av)
{	
	int	i;
	int	pid;

	i = 0;
	pid = ft_atoi(av[1]);
	if (ac == 3)
	{

	}
	while (av[2][i])
	{
		send_binary_signal(pid, 8, av[2][i]);
		usleep(100);
		i++;
	}
	send_binary_signal(pid, 8, '\n');
	pause();
}
