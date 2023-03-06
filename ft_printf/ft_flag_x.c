/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 02:06:30 by soleil            #+#    #+#             */
/*   Updated: 2022/11/30 02:07:28 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_x(unsigned int n)
{
	char	*base;
	int		r;

	base = "0123456789abcdef";
	r = 0;
	if (n >= 16)
	{
		r = r + ft_flag_x(n / 16);
		r = r + ft_flag_x(n % 16);
	}
	if (n <= 15)
	{
		ft_putchar(base[n]);
		r++;
	}
	return (r);
}

int	ft_x(va_list list)
{
	unsigned int	n;

	n = va_arg(list, unsigned int);
	return (ft_flag_x(n));
}
