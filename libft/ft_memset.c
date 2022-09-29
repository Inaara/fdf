/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:33:46 by pszleper          #+#    #+#             */
/*   Updated: 2021/11/27 23:32:32 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	converted;
	void			*temp;

	temp = b;
	converted = (unsigned char) c;
	i = 0;
	while (i < len)
	{
		*(unsigned char *) b = converted;
		b++;
		i++;
	}
	return (temp);
}
