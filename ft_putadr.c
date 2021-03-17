/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:58:57 by sobouatt          #+#    #+#             */
/*   Updated: 2021/03/07 12:00:42 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int        ft_putadr(unsigned long long n)
{
    int i;
    int ret;
    char *hex;
    char str[17];

    i = 0;
    hex = "0123456789abcdef";
	ret = ft_putstr("0x");
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
    ret += i;
    while (--i >= 0)
		ft_putchar(str[i]);
    return(ret);
}
