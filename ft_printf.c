#include "ft_printf.h"

int		ft_is_type(char c)
{
	int i;
	char *type;

	type = "cspduxX%";
	i = 0;
	while (type[i])
	{
		if (type[i] == c)
			return (1);
		i++;
	}
	return(0);
}

char	ft_return_type(const char *str, int *i)
{
	int j;
	char type[] = "cspduxX%";

	i = 0;
	while (str[*i])
	{
		j = 0;
		while (type[j])
		{
			if (str[*i] == type[j])
				return (type[j]);
			j++;
		}
		(*i)++;
	}
	return(' ');
}

void	ft_init_flags(t_flags *flags)
{
	flags->depht = 0;
	flags->star = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
}

int		ft_parsing(const char *str, va_list args, int *i)
{
	int ret;
	char c;
	t_flags flags;

	c = ft_return_type(str, i);
	ft_init_flags(&flags);
	ft_fill_flags(&flags, str, i);
	ret = ft_puthex(va_arg(args, unsigned int), c);
	return (1);
}

int		ft_printf(const char *str, ...)
{
	int		i;
	int		out;
	va_list	args;

	i = 0;
	out = 0;
	va_start(args, str);

	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			out += ft_parsing(str, args, &i);
		}
		else
			out += ft_putchar(str[i++]);
	}
	va_end(args);
	return (i);
}
