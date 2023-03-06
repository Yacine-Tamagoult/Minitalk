/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 02:20:32 by soleil            #+#    #+#             */
/*   Updated: 2022/11/30 02:23:15 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

void	ft_putstr(const char *str);
int		ft_printf(const char *str, ...);
void	ft_putchar(char c);
int		ft_checkflag(const char c);
int		ft_douane(char c, va_list list);
int		ft_flag_s(va_list list);
int		ft_flag_c(va_list list);
int		ft_flag_di(int n);
int		ft_di(va_list list);
int		ft_flag_u(unsigned int n);
int		ft_u(va_list list);
int		ft_flag_x(unsigned int n);
int		ft_x(va_list list);
int		ft_flag_upperx(unsigned int n);
int		ft_upx(va_list list);
int		ft_percent(void);
int		ft_flag_p(unsigned long int n);
int		ft_p(va_list list);

#endif