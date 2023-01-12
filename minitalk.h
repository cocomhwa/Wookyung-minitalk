/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooshin <wooshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:13:38 by wooshin           #+#    #+#             */
/*   Updated: 2023/01/12 21:11:21 by wooshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include "./library/ft_printf/ft_printf.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

typedef struct s_ascii{
	int		i;
	char	byte[8];
}				t_ascii;

int		ft_atoi(const char *str);
int		ft_atoi_base(char *str, char *base);

#endif
