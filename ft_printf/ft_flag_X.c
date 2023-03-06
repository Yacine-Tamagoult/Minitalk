/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 02:11:48 by soleil            #+#    #+#             */
/*   Updated: 2022/11/30 02:18:10 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_upperx(unsigned int n)
{
	char	*base;
	int		r;

	base = "0123456789ABCDEF";
	r = 0;
	if (n >= 16)
	{
		r = r + ft_flag_upperx(n / 16);
		r = r + ft_flag_upperx(n % 16);
	}
	if (n <= 15)
	{
		ft_putchar(base[n]);
		r++;
	}
	return (r);
}

int	ft_upx(va_list list)
{
	unsigned int	n;

	n = va_arg(list, unsigned int);
	return (ft_flag_upperx(n));
}
