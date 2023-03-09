/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:35:44 by soleil            #+#    #+#             */
/*   Updated: 2022/11/23 09:54:13 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = ft_strlen(dst);
	j = ft_strlen(src);
	if (n <= k)
		return (j + n);
	while (i < n - k - 1 && src[i])
	{	
		dst[k + i] = src[i];
		i++;
	}
	dst[k + i] = '\0';
	return (k + j);
}
