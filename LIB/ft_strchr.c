/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:47:42 by yatamago          #+#    #+#             */
/*   Updated: 2022/11/23 09:47:02 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return (ptr);
		}
		i++;
		ptr++;
	}
	if (s[i] == '\0' && c == '\0')
	{
		return (ptr);
	}
	return (NULL);
}
