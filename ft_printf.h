/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:25:34 by sobouatt          #+#    #+#             */
/*   Updated: 2021/03/17 14:36:07 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <libc.h>

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

typedef struct	s_flags
{
	int 		depht;
	int 		minus;
	int 		zero;
	int 		dot;
	int 		star;
}				t_flags;

int		ft_putchar(char c);
int 	ft_putstr(char *str);
int		ret_putnbr(int n);
int		ft_putadr(unsigned long long n);
int		ft_putnbr(int n, t_flags flags);
int		ft_putuns(unsigned int n);
int		ft_puthex(unsigned int n, char c);
int		parsing(char *str, va_list args);
int		ft_printf(const char *str, ...);
int		ft_atoi(char *str);
void	ft_fill_flags(t_flags *flags, const char *str, int *i);
void	ft_init_flags(t_flags *flags);

#endif
