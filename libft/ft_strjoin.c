/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:47:13 by pszleper          #+#    #+#             */
/*   Updated: 2021/12/20 16:40:36 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*returned;

	i = 0;
	j = 0;
	returned = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s1 != NULL && s2 != NULL && returned != NULL)
	{
		while (s1[i] != '\0')
		{
			returned[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			returned[i + j] = s2[j];
			j++;
		}
		returned[i + j] = '\0';
		return (returned);
	}
	return (0);
}
