/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_douane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:48:22 by yatamago          #+#    #+#             */
/*   Updated: 2022/11/30 02:17:22 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_douane(char c, va_list list)
{
	if (c == 's')
		return (ft_flag_s(list));
	if (c == 'c')
		return (ft_flag_c(list));
	if (c == 'd' || c == 'i')
		return (ft_di(list));
	if (c == 'u')
		return (ft_u(list));
	if (c == 'x')
		return (ft_x(list));
	if (c == 'X')
		return (ft_upx(list));
	if (c == '%')
		return (ft_percent());
	if (c == 'p')
		return (ft_p(list));
	return (0);
}
