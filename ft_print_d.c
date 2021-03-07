#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
		ft_putchar(str[i++]);
}

void	ft_putnbr_base(long long int nbr)
{
	long long int			nb;
	long long int			size;
	char *base;

	base = "0123456789abcdef";
	size = 16;
	if (nbr < 0)
	{
		ft_putchar('-');
		nb = -nbr;
	}
	else
		nb = nbr;
	if (nb >= size)
	{
		ft_putnbr_base(nb / size);
		ft_putnbr_base(nb % size);
	}
	else
		ft_putchar(base[nb]);
}
void	ft_putnbr(int n)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			n = 147483648;
		}
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	if (n < 10)
		ft_putchar(n + '0');
}

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

int		ft_check_global(const char *str)
{
	size_t i;
	size_t j;
	size_t count;
	char *verif;

	verif = "cspdiuxX%";
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (str[i] == ' ')
			{
				i++;
			}
			j = 0;
			while (verif[j] && str[i] != verif[j])
				j++;
			if (str[i] == verif[j])
				count++;
			else
				return(-1);
		}
		i++;
	}
	return (count);
}

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
