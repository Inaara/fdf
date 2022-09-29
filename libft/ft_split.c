/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 05:01:02 by pszleper          #+#    #+#             */
/*   Updated: 2021/12/18 01:24:32 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	word_count;
	size_t	i;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			word_count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word_count);
}

static char	*ft_alloc_and_copy_str(char const *s, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

static void	ft_free_all_substrs(char **strings_ptr, size_t current_index)
{
	if (!strings_ptr)
		return ;
	if (current_index == 0)
	{
		free(strings_ptr);
		return ;
	}
	while (current_index > 0)
	{
		current_index--;
		free(strings_ptr[current_index]);
	}
	free(strings_ptr);
}

char	**ft_split(char const *s, char c)
{
	char		**strings;
	size_t		i;
	size_t		strings_length;

	if (!s)
		return (NULL);
	strings_length = ft_word_count(s, c);
	strings = malloc(sizeof(char *) * (strings_length + 1));
	if (!strings)
		return (NULL);
	i = -1;
	while (++i < strings_length)
	{
		while (*s == c)
			s++;
		strings[i] = ft_alloc_and_copy_str(s, c);
		if (!strings[i])
		{
			ft_free_all_substrs(strings, i);
			return (NULL);
		}
		s += ft_strlen(strings[i]);
	}
	strings[i] = NULL;
	return (strings);
}
