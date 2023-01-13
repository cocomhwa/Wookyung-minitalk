/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooshin <wooshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:46:29 by wooshin           #+#    #+#             */
/*   Updated: 2023/01/13 23:44:18 by wooshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_binary_signal(int pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit++ < 8)
	{
		if (c % 2)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		c >>= 1;
	}
}

static void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_binary_signal(pid, message[i]);
		usleep(100);
		i++;
	}
	send_binary_signal(pid, '\n');
}

int	main(int ac, char **av)
{	
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_message(pid, av[2]);
	}
}
