/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:36:58 by pszleper          #+#    #+#             */
/*   Updated: 2021/12/10 18:01:39 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*ptr;
	size_t		i;

	i = 0;
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	while (i < size * count)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
