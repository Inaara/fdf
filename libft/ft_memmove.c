/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:54:55 by pszleper          #+#    #+#             */
/*   Updated: 2021/12/10 18:14:26 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy_from_to(unsigned char *dst, unsigned char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst >= src)
	{
		while (i < len)
		{
			dst[len - i - 1] = src[len - i - 1];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			dst[i] = src[i];
			i++;
		}
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destination;
	unsigned char	*source;

	if (!dst && !src)
		return (NULL);
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	ft_copy_from_to(destination, source, len);
	return (dst);
}
