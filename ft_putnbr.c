/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:01:50 by sobouatt          #+#    #+#             */
/*   Updated: 2021/03/08 21:18:31 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/*
int			ret_putnbr(int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return(i);
}
*/

int			ft_putnbr(int n)
{
	int ret;
	ret = 0;
	ret += 5;
	printf("n = %d\n", n);
	
	//ret = ret_putnbr(n);
//	printf("ret = %d\n", ret);
//	while (flags.depht > ret)
//	{
//		ret += ft_putchar(' ');
//		flags.depht--;
//	}

	if (n == -2147483648)
		ret += printf("-2147483648");
	else if (n < 0)
	{
		ret += ft_putchar('-');
		ret += ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ret += ft_putnbr(n / 10);
		ret += ft_putchar(n % 10 + '0');
	}
	else
		ret += ft_putchar(n + '0');
	return (ret);
}

int		main(void)
{
	printf("\nretour = %d\n", ft_putnbr(2147483647));
}
