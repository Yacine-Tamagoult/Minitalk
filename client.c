/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:06:37 by soleil            #+#    #+#             */
/*   Updated: 2023/03/07 19:44:28 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_controle = 0;

char	*zero(char *tab)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		tab[i] = '0';
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*calcul(int c)
{
	int		num;
	int		i;
	char	*tab;

	tab = malloc(sizeof(char) * 9);
	i = 0;
	num = c;
	while (num != 0)
	{
		tab[i++] = num % 2 + '0';
		num = num / 2;
	}
	if (c <= 63)
		tab[i++] = '0';
	if (c == 0)
	{
		zero(tab);
		return (tab);
	}
	tab[i] = '0';
	tab[++i] = '\0';
	swap (tab);
	return (tab);
}

void	send(int code, char *str)
{
	int	i;

	i = 0;
	while (str[i++] && g_controle == 0)
	{
		g_controle = 1;
		if (str[i] == '1')
		{
			if (kill(code, SIGUSR1))
			{
				ft_printf("ERROR Mauvais PID.\n");
				return ;
			}
			while (g_controle);
		}
		else if (str[i] == '0')
		{
			if (kill(code, SIGUSR2))
			{
				ft_printf("ERROR Mauvais PID.\n");
				return ;
			}
			while (g_controle); 
		}
	}
	free (str);
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
