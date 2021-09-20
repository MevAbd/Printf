/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 01:51:41 by malbrand          #+#    #+#             */
/*   Updated: 2021/09/16 05:37:00 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(unsigned long n, char *base)
{
	if (n == 0)
		return (ft_itoa_base_0(base));
	if (base == NULL)
		return (NULL);
	else
		return (ft_div_mod(n, base));
}

int	ft_len(unsigned long n, int len_base)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		n /= len_base;
		size++;
	}
	return (size);
}

char	*ft_div_mod(unsigned long n, char *base)
{
	int		size;
	int		mod;
	int		len_base;
	char	*str;

	len_base = ft_strlen(base);
	size = ft_len(n, len_base);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!(str))
		return (NULL);
	str[size] = '\0';
	size--;
	mod = 0;
	while (n > 0)
	{
		mod = n % len_base;
		str[size] = base[mod];
		n /= len_base;
		size--;
	}
	return (str);
}

char	*ft_itoa_base_0(char *base)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!(str))
		return (NULL);
	str[0] = base[0];
	str[1] = '\0';
	return (str);
}
