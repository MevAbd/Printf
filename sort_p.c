/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_p .c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:07:01 by malbrand          #+#    #+#             */
/*   Updated: 2021/09/16 05:39:07 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_p(const char *str, va_list argptr, int *ret)
{
	size_t			i;
	long long int	*ptr;

	i = 0;
	if (str[i] == '%')
	{
		i++;
		while (str[i] == ' ')
			i++;
		if (str[i] == 'p')
		{
			ptr = va_arg(argptr, long long int*);
			write(1, "0x", 2);
			*ret = *ret + 2;
			ft_putnbr_base((long long int)ptr, ret);
			va_end(argptr);
			i++;
		}
	}
	return (i);
}
