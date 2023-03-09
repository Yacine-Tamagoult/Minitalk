/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:38:22 by yatamago          #+#    #+#             */
/*   Updated: 2022/11/23 10:03:55 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
			i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	int		y;
	char	*p;

	i = 0;
	j = ft_strlen(s1);
	y = 0;
	while (s1[i] && ft_check(s1[i], set) == 1)
		i++;
	while (j > i && ft_check(s1[j - 1], set) == 1)
		j--;
	k = j - i;
	p = malloc(sizeof(char) * k + 1);
	if (!p)
		return (NULL);
	while (i < j)
	{
		p[y++] = s1[i++];
	}
	p[y] = '\0';
	return (p);
}
