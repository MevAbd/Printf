#include "printf.h"

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
