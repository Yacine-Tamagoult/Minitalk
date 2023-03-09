/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:38:43 by soleil            #+#    #+#             */
/*   Updated: 2023/03/09 01:14:26 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	swap(char *str)
{
	int		i;
	int		j;
	int		a;
	char	k;

	i = 0;
	j = ft_strlen(str) - 1;
	a = ft_strlen(str) / 2;
	while (i != a)
	{
		k = str[i];
		str[i] = str[j];
		str[j] = k;
		i++;
		j--;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	ba;

	ft_memset(&ba, 0, sizeof(ba));
	ba.sa_handler = test;
	sigaction(SIGUSR1, &ba, NULL);
	if (ac == 3)
	{
		master(ft_atoi(av[1]), av[2]);
		return (0);
	}
	else if (ac != 3)
	{
		ft_printf("Error");
		return (0);
	}
	return (0);
}
