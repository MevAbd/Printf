/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 01:52:44 by malbrand          #+#    #+#             */
/*   Updated: 2021/09/16 04:37:11 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_putnbr_base(long long int nbr, char c, int *ret)
{
	long long int	size;
	char			*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	size = 16;
	if (nbr >= size)
	{
		ft_unsigned_putnbr_base((nbr / size), c, ret);
		ft_unsigned_putnbr_base((nbr % size), c, ret);
	}
	else
	{
		ft_putchar(base[nbr]);
		*ret = *ret + 1;
	}
}

char	*ft_strdup(char const *s)
{
	size_t	len;
	char	*ret;
	size_t	i;

	len = ft_strlen(s) + 1;
	i = 0;
	ret = (char *)malloc(sizeof(char) * len);
	if (!(ret))
		return (NULL);
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
