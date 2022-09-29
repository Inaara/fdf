/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:24:53 by pszleper          #+#    #+#             */
/*   Updated: 2022/08/16 20:25:23 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// finds char c in s, returning its' position
// flag is used to reduce the number of lines to pass the norm but it's messy
// the -2 return is used to terminate the main loop once EOF is reached
// the -1 is used for the absence of newline, telling gnl to read more
int	ft_strchr_flag(char *s, int c, int flag)
{
	int	i;

	if (flag == 1 && !s)
		return (-2);
	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

// frees memory and sets pointer address to NULL to prevent potential segfaults
void	ft_free(void **p)
{
	free(*p);
	*p = NULL;
}

// same as libft, but only copies n chars to prevent segfaults
// used to append the newly read content to the line that has to be returned
char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s2[j] == '\0')
		return (NULL);
	output = malloc(ft_strlen(s1) + n + 1);
	if (!output)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			output[i] = s1[i];
			i++;
		}
	}
	while (s2 && s2[j] && j < n)
		output[i++] = s2[j++];
	output[i] = '\0';
	if (s1)
		ft_free((void **)&s1);
	return (output);
}
