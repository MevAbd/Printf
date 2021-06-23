#include "printf.h"

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
