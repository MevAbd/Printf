/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:07:01 by malbrand          #+#    #+#             */
/*   Updated: 2021/09/16 04:37:57 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_str_test(const char *str, va_list argptr, int *ret)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	if (str[i] == '%')
	{
		while (str[i + j] == ' ')
			j++;
		if (str[i + j] == 'd' || str[i + j] == 'i' || str[i + j] == 'c')
			i = i + ft_str_test1(&str[i], argptr, ret);
		if (str[i + j] == 's' || str[i + j] == 'p')
			i = i + ft_str_test2(&str[i], argptr, ret);
		if (str[i + j] == 'u' || str[i + j] == 'x' || str[i + j] == 'X')
			i = i + ft_str_test3(&str[i], argptr, ret);
	}
	if (str[i] == '%' && str[i + 1] == '%')
	{
		write(1, "%", 1);
		*ret = *ret + 1;
		i += 2;
	}
	return (i);
}

size_t	ft_str_test1(const char *str, va_list argptr, int *ret)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	if (str[i] == '%')
	{
		while (str[i + j] == ' ')
			j++;
		if (str[i + j] == 'd' || str[i + j] == 'i')
		{
			i = i + ft_d_i(&str[i], argptr, ret);
			j = 1;
		}
		if (str[i + j] == 'c')
		{
			i = i + ft_c(&str[i], argptr, ret);
			j = 1;
		}
	}
	return (i);
}

size_t	ft_str_test2(const char *str, va_list argptr, int *ret)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	if (str[i] == '%')
	{
		while (str[i + j] == ' ')
			j++;
		if (str[i + j] == 's')
		{
			i = i + ft_s(&str[i], argptr, ret);
			j = 1;
		}
		if (str[i + j] == 'p')
		{
			i = i + ft_p(&str[i], argptr, ret);
			j = 1;
		}
	}	
	return (i);
}

size_t	ft_str_test3(const char *str, va_list argptr, int *ret)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	if (str[i] == '%')
	{
		while (str[i + j] == ' ')
			j++;
		if (str[i + j] == 'u')
		{
			i = i + ft_u(&str[i], argptr, ret);
			j = 1;
		}
		if (str[i + j] == 'x' || str[i + j] == 'X')
		{
			i = i + ft_x(&str[i], argptr, ret);
			j = 1;
		}
	}	
	return (i);
}
