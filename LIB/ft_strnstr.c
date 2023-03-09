/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:40:33 by soleil            #+#    #+#             */
/*   Updated: 2022/11/23 09:59:44 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[0] == '\0')
	{
		return ((char *) s1);
	}
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		if (s1[i] == s2[j])
		{	
			while ((s1[i + j] == s2[j]) && i + j < n)
			{
				j++;
				if (s2[j] == 0)
				{
					return ((char *)(&s1[i]));
				}
			}
		}
		i++;
	}			
	return (NULL);
}
