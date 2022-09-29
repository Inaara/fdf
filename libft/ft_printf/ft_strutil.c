/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:35:23 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/24 16:20:19 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	ft_putstr_hex(char *str)
{
	int	len;
	int	pos;

	len = 0;
	pos = 0;
	while (*str == '0' && pos != 7)
	{
		str++;
		pos++;
	}
	while (*str)
	{
		write(1, str++, 1);
		len++;
	}
	return (len);
}

int	ft_putstr_address(char *str)
{
	int	len;
	int	pos;

	len = 0;
	pos = 0;
	while (*str == '0' && pos != 15)
	{
		str++;
		pos++;
	}
	while (*str)
	{
		write(1, str++, 1);
		len++;
	}
	return (len);
}
