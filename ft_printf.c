/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:11:56 by sobouatt          #+#    #+#             */
/*   Updated: 2021/02/10 15:12:46 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

// ok
int ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
}

// ok
int 	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return(i);
}

// ok
int		ret_putnbr(int n)
{
	int i;

	i = 0;
	while(n != 0)
	{
		n /= 10;
		i++;
	}
	return(i);
}

//ok
int		ft_putuns(unsigned int n)
{
	int ret;

	ret = ret_putnbr(n);
	if (n >= 10)
	{
		ft_putuns(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
	return(ret);
}

// ok
int			ft_putnbr(int n)
{
	int ret;

	ret = ret_putnbr(n);
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
	return (ret);
}

// ok ?
int        put_hex(int n)
{
    int i;
    int ret;
    char *hex;
    char str[8];

    i = 0;
    hex = "0123456789abcdef";
    if (n == 0)
    {
        ft_putchar('0');
		return (1);
    }
    while (n > 0)
    {
        str[i] = hex[n%16];
        n /= 16;
        i++;
    }
    ret = i;
    while (--i >= 0)
		ft_putchar(str[i]);
    return(ret);
}

int        put_bighex(int n)
{
    int i;
    int ret;
    char *hex;
    char str[8];

    i = 0;
    hex = "0123456789ABCDEF";
    if (n == 0)
    {
        ft_putchar('0');
		return (1);
    }
    while (n > 0)
    {
        str[i] = hex[n%16];
        n /= 16;
        i++;
    }
    ret = i;
    while (--i >= 0)
		ft_putchar(str[i]);
    return(ret);
}

// ko
int		parsing(char c, va_list args)
{
	int ret;

	ret = 0;
	if (c == 'c')
		ret = ft_putchar(va_arg(args, int));
	if (c == 's')
		ret = ft_putstr(va_arg(args, char *));
	if (c == 'p') 
		ret = 0;
	if (c == 'd')
		ret = ft_putnbr(va_arg(args, int));
	if (c == 'u')
		ret = ft_putuns(va_arg(args, unsigned int));
	if (c == 'x')
		ret = put_hex(va_arg(args, unsigned int));
	if (c == 'X')
		ret = put_bighex(va_arg(args, unsigned int));
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
			i++;
			out += parsing(str[i], args);
			i++;
		}
		else
		{
			out += ft_putchar(str[i]);
			i++;
		}
	}
	return(out);
}
/*
int		main(void)
{
	printf("printf = %d\n", printf("the answer to life is %X\n", 987654321));
	printf("ft_printf = %d\n", ft_printf("the answer to life is %X\n", 987654321));
	return(0);
}
*/
