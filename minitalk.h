#ifndef MINITALK_H
# define MINITALK_H

#include "./library/ft_printf/ft_printf.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

typedef struct s_ascii{
	int	i;
	int	byte[8];
}				t_ascii;

#endif
