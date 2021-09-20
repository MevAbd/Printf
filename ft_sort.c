/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 01:51:41 by malbrand          #+#    #+#             */
/*   Updated: 2021/09/16 05:37:00 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_u(const char *str, va_list argptr, int *ret)
{
	size_t			i;
	int				nb;
	unsigned int	nbr;

	i = 0;
	nb = 0;
	nbr = 0;
	if (str[i] == '%')
	{
		i++;
		while (str[i] == ' ')
			i++;
		nb = va_arg(argptr, int);
		nbr = (unsigned int)nb;
		if (str[i] == 'u')
		{
			ft_unsigned_putnbr(nbr, ret);
			va_end(argptr);
			i++;
		}
	}
	return (i);
}

size_t	ft_x(const char *str, va_list argptr, int *ret)
{
	size_t			i;
	int				nb;
	unsigned int	nbr;

	i = 0;
	nb = 0;
	nbr = 0;
	if (str[i] == '%')
	{
		i++;
		while (str[i] == ' ')
			i++;
		nb = va_arg(argptr, int);
		nbr = (unsigned int)nb;
		if (str[i] == 'x' || str[i] == 'X')
		{
			ft_unsigned_putnbr_base(nbr, str[i], ret);
			va_end(argptr);
			i++;
		}
	}
	return (i);
}

size_t	ft_d_i(const char *str, va_list argptr, int *ret)
{
	size_t	i;
	int		nb;

	i = 0;
	nb = 0;
	if (str[i] == '%')
	{
		i++;
		while (str[i] == ' ')
			i++;
		if (str[i] == 'd' || str[i] == 'i')
		{
			if (str[i - 1] == ' ')
			{
				write (1, " ", 1);
				*ret = *ret + 1;
			}
			nb = va_arg(argptr, int);
			ft_putnbr(nb, ret);
			va_end(argptr);
			i++;
		}
	}
	return (i);
}

size_t	ft_c(const char *str, va_list argptr, int *ret)
{
	char	c;
	size_t	i;

	i = 0;
	if (str[i] == '%')
	{
		i++;
		while (str[i] == ' ')
			i++;
		if (str[i] == 'c')
		{
			c = va_arg(argptr, int);
			write(1, &c, 1);
			*ret = *ret + 1;
			va_end(argptr);
			i++;
		}
	}
	return (i);
}

size_t	ft_s(const char *str, va_list argptr, int *ret)
{
	const char	*test;
	size_t		i;

	i = 0;
	if (str[i] == '%')
	{
		i++;
		if (str[i] == 's')
		{
			test = va_arg(argptr, const char *);
			if (!test)
			{
				write(1, "(null)", 6);
				*ret = *ret + 6;
				i++;
			}
			if (test)
			{
				ft_putstr(test, ret);
				i++;
			}
		}
	}
	return (i);
}
