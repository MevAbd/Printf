/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 01:54:11 by malbrand          #+#    #+#             */
/*   Updated: 2021/09/16 05:04:16 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int		ret;
	va_list	argptr;

	i = 0;
	ret = 0;
	va_start(argptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_str_test(&str[i], argptr, &ret);
			while (str[i + 1] == ' ')
				i++;
			i += 2;
		}
		else
		{
			write(1, &str[i], 1);
			ret = ret + 1;
			i++;
		}
	}
	va_end(argptr);
	return (ret);
}
