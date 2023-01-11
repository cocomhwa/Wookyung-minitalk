/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooshin <wooshin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:56:49 by wooshin           #+#    #+#             */
/*   Updated: 2022/12/28 11:38:57 by wooshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		check_print(const char c, va_list *list);
int		ft_strleng(const char *s);
int		ft_putchar_count(int c);
int		ft_putstr_count(char *s);
int		put_ptr(unsigned long p);
int		ft_putptr_count(void *ptr);
int		put_hex(unsigned int num, const char c);
int		ft_puthex_count(unsigned int num, const char c);
int		ft_putnbr_count(int num);
int		put_unsigned(unsigned int num);
int		ft_un_putnbr_count(unsigned int num);
void	ft_putnbr(int num);
void	ft_putchar(char c);
void	ft_putstr(char *s);

#endif
