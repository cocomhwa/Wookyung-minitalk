/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooshin <wooshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:46:29 by wooshin           #+#    #+#             */
/*   Updated: 2023/01/12 20:45:44 by wooshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_binary_signal(int pid, int bit, unsigned char c)
{
	while (bit > 0)
	{
	ft_printf("%d\n", (int)c);
		if (c % 2)
			kill(pid, SIGUSR2);
		else if (c % 2 == 0)
			kill(pid, SIGUSR1);
		usleep(100);
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
	//send_binary_signal(pid, 8, '\n');
}
