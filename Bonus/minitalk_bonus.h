/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:11:17 by soleil            #+#    #+#             */
/*   Updated: 2023/03/09 01:38:04 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "/home/soleil/Desktop/Minitalk/ft_printf/ft_printf.h"
# include "/home/soleil/Desktop/Minitalk/LIB/libft.h"

char	*ft_strcat(char *str, char c);
void	printstr(char c);
void	converter(char *str);
void	user1(int ref, siginfo_t *siginfo, void *context);
void	master(int code, char *str);
void	send(int code, char *str);
char	*calcul(int c);
void	swap(char *str);
void	test(int ref);
char	*zero(char *tab);

#endif