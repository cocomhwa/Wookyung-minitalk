/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooshin <wooshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:46:34 by wooshin           #+#    #+#             */
/*   Updated: 2023/01/13 23:55:24 by wooshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}

static void	print_flipped(char bits[8])
{
	int		i;
	char	c;

	i = 8;
	c = 0;
	while (i--)
	{
		c <<= 1;
		c += bits[i];
	}
	write(1, &c, 1);
}

static void	handle_binary_signal(int sig)
{
	static int	i = 0;
	static char	bits[8];

	bits[i++] = sig == SIGUSR2;
	if (i == 8)
	{
		print_flipped(bits);
		i = 0;
		ft_memset(bits, 0, 8);
	}
}

int	main(void)
{
	ft_printf("server pid : %d\n", getpid());
	signal(SIGUSR1, handle_binary_signal);
	signal(SIGUSR2, handle_binary_signal);
	while (1)
		pause();
}
