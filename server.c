/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooshin <wooshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:46:34 by wooshin           #+#    #+#             */
/*   Updated: 2023/01/12 22:08:15 by wooshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_ascii	g_sigascii;

void	sigtoa(int sig)
{
	
	unsigned char	num;

	num = 0;
	if (sig == 30)
		num = '0';
	else
		num = '1';
	g_sigascii.byte[g_sigascii.i++] = num;
	if (g_sigascii.i == 8)
	{
		ft_printf("%c is atoi", ft_atoi_base(g_sigascii.byte, "01"));
		ft_printf("%c is g_i\n", g_sigascii.byte[g_sigascii.i]);
		ft_printf("%c", num);
		g_sigascii.i = 0;	
	}
	ft_printf("%d is g_i\n", g_sigascii.i);
}

int	main(void)
{
	g_sigascii.i = 0;	
	ft_printf("server pid : %d\n", getpid());
	signal(SIGUSR1, sigtoa);
	signal(SIGUSR2, sigtoa);
	while (1)
		pause();
}
