/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:32:05 by malbrand          #+#    #+#             */
/*   Updated: 2021/06/28 05:52:12 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list param;
	int		i;
	int		ret;
	t_param *params;

	va_start(param, str);
	i = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			param = complete_struct(&str[i], p
		}
		ft_putchar(str[i]);
		ret = ret + 1;
		i++;
	}
	va_end(param);
	return (ret);
}

int main ()
{
	int ret; 

	ret = ft_printf("rouge\n");
	printf("ret = %d\n", ret);
}
