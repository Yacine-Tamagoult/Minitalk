/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:31:29 by yatamago          #+#    #+#             */
/*   Updated: 2022/11/23 10:05:00 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	maxlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= maxlen(s))
	{
		res = malloc(1);
		res[0] = '\0';
		return (res);
	}
	if (maxlen(s + start) < len)
		res = malloc((maxlen(s + start) + 1) * sizeof(char));
	else
		res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s[start + i] && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
