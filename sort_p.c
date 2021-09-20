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
	void			*adress;
	long long		nb;
	char			*str_nb;

	i = 0;
	str_nb = NULL;
	if (str[i] == '%')
	{
		i++;
		while (str[i] == ' ')
			i++;
		if (str[i] == 'p')
		{
			adress = va_arg(argptr, void *);
			nb = (long long)adress;
			str_nb = ft_itoa_base(nb, "0123456789abcdef");
			ft_putstr("0x", ret);
			ft_putstr(str_nb, ret);
			free(str_nb);
		}
	}
	return (i);
}
