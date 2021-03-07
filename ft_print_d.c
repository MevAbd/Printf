#include "printf.h"

int		ft_printf(const char *str, ...)
{
	size_t 		i;
	int		nb;
	char 		c;
	const char 	*test;
	long long int	*ptr;
	va_list 	argptr;

	i = 0;
	va_start(argptr, str);
	if (ft_check_global(str) == -1)
	{
		write(1, "ERROR_CHECK_GLOBAL\n", 19);
		return (-1);
	}
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			write(1 , "%", 1);
			i += 2;
		}
		if (str[i] == '%')
		{
			i++;
			while (str[i] == ' ')
				i++;
			if (str[i] == 'd')
			{
				nb = va_arg(argptr, int);
				ft_putnbr(nb);
				va_end(argptr);
				i++;
			}
			else if (str[i] == 'c')
			{
				c = va_arg(argptr, int);
				ft_putchar(c);
				va_end(argptr);
				i++;
			}
			else if (str[i] == 's')
			{
				test = va_arg(argptr, const char *);
				ft_putstr(test);
				va_end(argptr);
				i++;
			}
			else if (str[i] == 'p')
			{
				ptr = va_arg(argptr, long long int  *);
				ft_putchar('0');
				ft_putchar('x');
				ft_putnbr_base((long long int)ptr);
				va_end(argptr);
				i++;

			}

		}
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

int		main()
{
	int c;

	c = 'd';
	printf("address c = %p\n", &c);
	ft_printf("address c = %p\n", &c);
	return (0);
}
