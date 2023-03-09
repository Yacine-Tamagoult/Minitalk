/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:15:29 by soleil            #+#    #+#             */
/*   Updated: 2022/11/23 09:21:46 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	size_t		total;
	char		*p;

	i = 0;
	total = count * size;
	if ((long int)count < 0 || (long int)size < 0)
	{
		return (NULL);
	}
	p = malloc(total);
	if (p == NULL)
		return (NULL);
	while (i < total)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
