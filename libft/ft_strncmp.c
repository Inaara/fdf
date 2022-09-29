/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:55:46 by pszleper          #+#    #+#             */
/*   Updated: 2022/05/22 04:12:05 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;
	int		result;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] && s2[i] && s1[i] == s2[i] && i + 1 < n)
	{
		i++;
	}
	result = (unsigned char) s1[i] - (unsigned char) s2[i];
	if (result > 0)
		return (1);
	if (result < 0)
		return (-1);
	return (result);
}
