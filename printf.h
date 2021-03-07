#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(const char *str);
void	ft_putnbr(int n);
void	ft_putnbr_base(long long int nbr);
int	ft_check(const char *str);
int	ft_check_global(const char *str);

#endif
