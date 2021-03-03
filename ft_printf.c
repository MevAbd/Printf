/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:32:05 by malbrand          #+#    #+#             */
/*   Updated: 2021/03/03 11:21:25 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>


int		ft_check(const char *str)
{
	size_t 	i;
	size_t 	j;
	char	*verif;

	verif = "cspdiuxX";
	j = 0;
	i = 1;
	while (verif[j])
	{
		if (verif[j] == str[i])
			return (j);
		j++;
	}
	return (-1);
}

int		ft_printf(const char *str, ...)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_check(str + i) == -1)
				return (-1);
			else 
				return (0);
		}
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

int		main()
{
	ft_printf("1 coucou %d");
	ft_printf("2 coucou %h");
	printf("%d\n", ft_printf("3 coucou %h"));
	return (0);
}
