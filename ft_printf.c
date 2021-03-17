/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:11:56 by sobouatt          #+#    #+#             */
/*   Updated: 2021/02/10 15:12:46 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	ft_typeret(char *str)
{
	int i;
	int j;
	char type[] = "cspduxX%";

	i = 0;
	while (str[i])
	{
		j = 0;
		while (type[j])
		{
			if (str[i] == type[j])
				return (type[j]);
			j++;
		}
		i++;
	}
	return(' ');
}

void	ft_initflags(t_flags *flags)
{
	flags->depht = 0;
	flags->star = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
}


void	ft_fillflags(t_flags *flags, char *str)
{
	flags->depht = ft_atoi(str);
}

int		parsing(char *str, va_list args)
{
	int ret;
	char c;
	c = ft_typeret(str);
	t_flags flags;
	ft_initflags(&flags);
	ft_fillflags(&flags, str);
	if (c == 'c')
		ret = ft_putchar(va_arg(args, int));
	if (c == 's')
		ret = ft_putstr(va_arg(args, char *));
	if (c == 'p') 
		ret = ft_putadr(va_arg(args, unsigned long long));
	if (c == 'd')
		ret = ft_putnbr(va_arg(args, int), flags);
	if (c == 'u')
		ret = ft_putuns(va_arg(args, unsigned int));
	if (c == 'x')
		ret = ft_puthex(va_arg(args, unsigned int), c);
	if (c == 'X')
		ret = ft_puthex(va_arg(args, unsigned int), c);
	if (c == '%')
		ret = ft_putchar('%');

	return (ret);
}

// ko
int		ft_printf(const char *str, ...)
{
	int i;
	va_list args;
	int out;

	out = 0;
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if(str[i] == '%')
		{
			out += parsing((char*)(str + (++i)), args);
			i++;
		}
		else
			out += ft_putchar(str[i++]);
	}
	return (out);
}

int		main(void)
{
	printf("printf = %d\n", printf("%%d = %10d\n", 678534));
	printf("ft_printf = %d\n", ft_printf("%%d = %10d\n", 678534));
	return(0);
}
