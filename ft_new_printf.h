/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 04:20:45 by malbrand          #+#    #+#             */
/*   Updated: 2021/06/28 05:35:35 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct		s_param
{
	int				point;
	char			flag;
	int				first_width;
	int				second_width;
	char			conv_indic;
	int				increment;
	
}					t_param;

void	ft_putchar(char c);

#endif
