/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:21:55 by yatamago          #+#    #+#             */
/*   Updated: 2022/11/23 09:42:21 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	long unsigned int	i;
	unsigned char		*ptr;

	i = 0;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (ptr);
}
