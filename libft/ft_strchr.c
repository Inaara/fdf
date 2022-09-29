/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:10:32 by pszleper          #+#    #+#             */
/*   Updated: 2021/12/06 22:29:22 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	converted;

	ptr = (char *)s;
	converted = (char) c;
	while (*ptr)
	{
		if (*ptr == converted)
			return (ptr);
		ptr++;
	}
	if (*ptr == '\0' && *ptr == converted)
		return (ptr);
	return (NULL);
}
