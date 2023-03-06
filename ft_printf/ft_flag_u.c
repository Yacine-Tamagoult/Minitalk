/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:08:50 by yatamago          #+#    #+#             */
/*   Updated: 2022/11/30 02:04:01 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_u(unsigned int n)
{
	int	r;

	r = 0;
	if (n > 9)
	{
		r = r + ft_flag_u(n / 10);
		r = r + ft_flag_u(n % 10);
	}
	if (n <= 9)
	{
		ft_putchar(n + 48);
		r++;
	}
	return (r);
}

int	ft_u(va_list list)
{
	unsigned int	n;

	n = va_arg(list, unsigned int);
	return (ft_flag_u(n));
}
