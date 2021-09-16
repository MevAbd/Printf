#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

size_t	ft_str_test(const char *str, va_list argptr, int *ret);
size_t	ft_d_i(const char *str, va_list argptr, int *ret);
void	ft_putnbr(int nb, int *ret);
void	ft_putchar(char c);
int	ft_printf(const char *str, ...);
size_t	ft_c(const char *str, va_list argptr, int *ret);
void	ft_putstr(const char *str, int *ret);
size_t	ft_s(const char *str, va_list argptr, int *ret);
void	ft_putnbr_base(long long int nbr, int *ret);
size_t	ft_p(const char *str, va_list argptr, int *ret);
size_t	ft_str_test2(const char *str, va_list argptr, int *ret);
void	ft_unsigned_putnbr(unsigned int n, int *ret);
size_t	ft_str_test3(const char *str, va_list argptr, int *ret);
size_t	ft_u(const char *str, va_list argptr, int *ret);
void	ft_unsigned_putnbr_base(long long int nbr, char c, int *ret);
size_t	ft_str_test1(const char *str, va_list argptr, int *ret);
size_t	ft_x(const char *str, va_list argptr, int *ret);
char	*ft_strdup(char const *s);
size_t	ft_strlen(char const *s);

#endif
