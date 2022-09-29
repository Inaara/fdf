/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:11:10 by pszleper          #+#    #+#             */
/*   Updated: 2021/12/04 16:12:41 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_unsigned_char;
	unsigned char	*s2_unsigned_char;

	i = 0;
	s1_unsigned_char = (unsigned char *) s1;
	s2_unsigned_char = (unsigned char *) s2;
	while (i < n)
	{
		if (s1_unsigned_char[i] != s2_unsigned_char[i])
			return (s1_unsigned_char[i] - s2_unsigned_char[i]);
		i++;
	}
	return (0);
}
