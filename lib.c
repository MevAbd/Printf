/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 01:53:45 by malbrand          #+#    #+#             */
/*   Updated: 2021/09/16 04:36:54 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb, int *ret)
{
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		*ret = *ret + 1;
		if (nb == -2147483648)
		{
			write (1, "2", 1);
			*ret = *ret + 1;
			nb = 147483648;
		}
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, ret);
		ft_putchar((nb % 10) + '0');
		*ret = *ret + 1;
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		*ret = *ret + 1;
	}
}

void	ft_putstr(const char *str, int *ret)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
		*ret = *ret + 1;
	}
}

void	ft_putnbr_base(long long int nbr, int *ret)
{
	long long int	nb;
	long long int	size;
	char			*base;

	base = "0123456789abcdef";
	size = 16;
	if (nbr < 0)
	{
		ft_putchar('-');
		*ret = *ret + 1;
		nb = -nbr;
	}
	else
		nb = nbr;
	if (nb >= size)
	{
		ft_putnbr_base(nb / size, ret);
		ft_putnbr_base(nb % size, ret);
	}
	else
	{
		ft_putchar(base[nb]);
		*ret = *ret + 1;
	}
}

void	ft_unsigned_putnbr(unsigned int n, int *ret)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, ret);
		ft_putchar((n % 10) + '0');
		*ret = *ret + 1;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		*ret = *ret + 1;
	}
}
