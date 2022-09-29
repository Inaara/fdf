/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 04:38:46 by pszleper          #+#    #+#             */
/*   Updated: 2021/12/06 21:31:31 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	length_dst;
	size_t	length_src;
	size_t	i;

	length_src = ft_strlen(src);
	length_dst = ft_strlen(dst);
	if (dstsize <= length_dst)
		return (dstsize + length_src);
	i = 0;
	while (src[i] != '\0' && (length_dst + i) < (dstsize - 1))
	{
		dst[length_dst + i] = src[i];
		i++;
	}
	dst[length_dst + i] = '\0';
	return (length_dst + length_src);
}
