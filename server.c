/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:23:08 by soleil            #+#    #+#             */
/*   Updated: 2023/03/07 17:49:57 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid_client = 0;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *str, char c)
{
	int		i;
	char	*new;

	i = 0;
	if (!str)
		new = malloc(sizeof(char) * 2);
	else
	{
		new = malloc(sizeof(char) * (ft_strlen(str) + 2));
		while (str[i])
		{
			new[i] = str[i];
			i++;
		}
	}
	new[i] = c;
	new[i + 1] = 0;
	free (str);
	return (new);
}

void	printstr(char c)
{
	static char	*chaine;

	if (c == 0)
	{
		ft_printf("%s\n", chaine);
		free (chaine);
		chaine = NULL;
	}
	else
		chaine = ft_strcat(chaine, c);
}

void	converter(char *str)
{
	static int	i;
	char		c;

	while (str[i])
	{
		if (str[i] == '1')
		{
			c = c * 2 + 1;
			i++;
		}
		else if (str[i] == '0')
		{
			c = c * 2;
			i++;
		}
	}
	i = 0;
	printstr (c);
}

void	user1(int ref, siginfo_t *siginfo, void *context)
{
	static int	i;
	static char	str[8];

	g_pid_client = siginfo->si_pid;
	(void)context;
	if (i < 8)
	{
		if (ref == SIGUSR1)
		{
			str[i] = '1';
			i++;
		}
		else if (ref == SIGUSR2)
		{
			str[i] = '0';
			i++;
		}
	}
	if (i == 8)
	{
		i = 0;
		converter (str);
	}
	kill (g_pid_client, SIGUSR1);
}
