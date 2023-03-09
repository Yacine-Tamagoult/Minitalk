/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:06:37 by soleil            #+#    #+#             */
/*   Updated: 2023/03/09 01:15:13 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_controle = 0;

int	killer_one(int code)
{
	if (kill(code, SIGUSR1))
	{
		ft_printf("ERROR Mauvais PID.\n");
		return (1);
	}
	return (0);
}

int	killer_zero(int code)
{
	if (kill(code, SIGUSR2))
	{
		ft_printf("ERROR Mauvais PID.\n");
		return (1);
	}
	return (0);
}

void	send(int code, char *str)
{
	int	i;

	i = 0;
	while (str[i] && g_controle == 0)
	{
		if (str[i] == '1')
		{
			g_controle = 1;
			if (killer_one(code))
				return (free(str));
			while (g_controle)
				;
		}
		else if (str[i] == '0')
		{
			g_controle = 1;
			if (killer_zero(code) == 1)
				return (free(str));
			while (g_controle)
				;
		}
		i++;
	}
	free(str);
}

void	master(int code, char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (code == -1 || code == 0)
		{
			ft_printf("ERROR Mauvais PID.\n");
			return ;
		}
		send (code, calcul(str[i]));
		i++;
		if (str[i] == '\0')
		{
			send (code, calcul(j));
		}
	}
}

void	test(int ref)
{
	if (ref == SIGUSR1)
	{
		g_controle = 0;
	}
}
