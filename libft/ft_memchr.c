/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:32:17 by pszleper          #+#    #+#             */
/*   Updated: 2021/12/03 10:32:17 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	converted_char;
	size_t			i;

	ptr = (unsigned char *)s;
	converted_char = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (*ptr == converted_char)
			return (ptr);
		ptr++;
		i++;
	}
	return (NULL);
}
