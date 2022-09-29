/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:18:50 by pszleper          #+#    #+#             */
/*   Updated: 2021/12/10 17:50:43 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	ft_is_in_set(char const c, char const *set)
{
	int	len;
	int	i;

	len = ft_strlen(set);
	i = 0;
	while (i < len)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	start_str;
	size_t	end_str;
	char	*mem_ptr;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	start_str = 0;
	end_str = 0;
	while (i < len && ft_is_in_set(s1[i], set))
		i++;
	start_str = i;
	i = len;
	while (len-- && ft_is_in_set(s1[len], set))
		i--;
	end_str = i - 1;
	mem_ptr = ft_substr(s1, start_str, end_str - start_str + 1);
	if (!mem_ptr)
		return (NULL);
	return (mem_ptr);
}
