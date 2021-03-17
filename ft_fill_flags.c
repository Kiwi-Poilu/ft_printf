/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:09:14 by sobouatt          #+#    #+#             */
/*   Updated: 2021/03/17 14:44:55 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_flags(t_flags *flags)
{
	printf("depht = %d\n", flags->depht);
	printf("star = %d\n", flags->star);
	printf("minus = %d\n", flags->minus);
	printf("zero = %d\n", flags->zero);
	printf("dot = %d\n", flags->dot);
}

void	ft_init_flags(t_flags *flags)
{
	flags->depht = 0;
	flags->star = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_fill_flags(t_flags *flags, const char *str, int *i)
{
	if (ft_isdigit(str[*i]))
		flags->depht = atoi((char *)str + *i);
	ft_print_flags(flags);
}

int		main(void)
{
	int i;

	i = 0;
	t_flags flags;
	ft_init_flags(&flags);
	ft_fill_flags(&flags, "254sofiane", &i);
}
