/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:09:14 by sobouatt          #+#    #+#             */
/*   Updated: 2021/03/17 14:12:53 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_fill_flags(t_flags *flags, const char *str, int *i)
{
	(*i)++;
	flags->dot = 0;
	printf("%s\n", str);
}
