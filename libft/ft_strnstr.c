/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 10:01:43 by pszleper          #+#    #+#             */
/*   Updated: 2021/12/04 16:14:31 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (haystack[j] && i < len)
	{
		while (haystack[j] && haystack[j] == needle[k] && (i + j) < len)
		{
			if (needle[k + 1] == '\0')
				return ((char *) haystack + j - k);
			j++;
			k++;
		}
		j = 0;
		k = 0;
		haystack++;
		i++;
	}
	return (NULL);
}
