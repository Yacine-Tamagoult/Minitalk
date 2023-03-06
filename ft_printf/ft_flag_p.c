/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:37:29 by soleil            #+#    #+#             */
/*   Updated: 2022/11/30 02:00:59 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_p(unsigned long int n)
{
	char		*base;
	int			r;

	r = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		r = r + ft_flag_p(n / 16);
		r = r + ft_flag_p(n % 16);
	}
	if (n <= 15)
	{
		ft_putchar(base[n]);
		r++;
	}
	return (r);
}

int	ft_p(va_list list)
{
	unsigned long int	n;

	n = va_arg(list, unsigned long int);
	if (n != 0)
	{
		write(1, "0x", 2);
		return (ft_flag_p(n) + 2);
	}
	else if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	return (0);
}
