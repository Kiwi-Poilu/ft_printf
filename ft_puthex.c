/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:00:49 by sobouatt          #+#    #+#             */
/*   Updated: 2021/03/17 14:05:59 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int        ft_puthex(unsigned int n, char c)
{
    int i;
    int ret;
    char *hex;
    char str[8];

    i = 0;
    if (c == 'x')
		hex = "0123456789abcdef";
	else if (c == 'X')
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
