/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:46:38 by yatamago          #+#    #+#             */
/*   Updated: 2022/11/30 01:57:21 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_di(int n)
{
	int	r;

	r = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
		r = r + 1;
	}
	if (n > 9)
	{
		r = r + ft_flag_di(n / 10);
		r = r + ft_flag_di(n % 10);
	}
	if (n <= 9)
	{
		ft_putchar(n + 48);
		r++;
	}
	return (r);
}

int	ft_di(va_list list)
{
	int	n;

	n = va_arg(list, int);
	return (ft_flag_di(n));
}
