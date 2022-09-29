/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:30:35 by pszleper          #+#    #+#             */
/*   Updated: 2021/12/06 22:39:58 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	converted;
	size_t	length_str;

	ptr = (char *)s;
	converted = (char) c;
	length_str = ft_strlen(s);
	ptr = ptr + length_str;
	while (*ptr != converted)
	{
		if (ptr == s)
			return (NULL);
		ptr--;
	}
	return (ptr);
}
