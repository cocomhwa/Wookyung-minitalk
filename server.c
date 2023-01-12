/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooshin <wooshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:46:34 by wooshin           #+#    #+#             */
/*   Updated: 2023/01/12 18:42:28 by wooshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_ascii	g_sigascii;

void	sigtoa(int sig)
{
	if (sig == 30)
		sig = 0;
	else
		sig = 1;

	
}

int	main(void)
{
	
	ft_printf("server pid : %d\n", getpid());
	signal(SIGUSR1, sigtoa);
	signal(SIGUSR2, sigtoa);
	pause();
}
