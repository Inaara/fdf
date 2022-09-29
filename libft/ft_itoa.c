/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:02:43 by pszleper          #+#    #+#             */
/*   Updated: 2022/05/22 04:13:02 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int	length_nb;
	int	divider;

	if (n == 0)
		return (1);
	length_nb = 10;
	divider = 1000000000;
	if (n < 0)
		length_nb++;
	while (n / divider == 0 && length_nb > 0)
	{
		length_nb--;
		divider /= 10;
	}
	return (length_nb);
}

static char	*ft_allocate_memory_for_number(int n)
{
	char	*mem_ptr;
	int		length_nb;

	length_nb = ft_intlen(n);
	mem_ptr = malloc(sizeof(char) * length_nb + 1);
	if (!mem_ptr)
		return (NULL);
	if (n < 0)
		mem_ptr[0] = '-';
	mem_ptr[length_nb] = '\0';
	return (mem_ptr);
}

int	ft_abs_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		length_nb;

	result = ft_allocate_memory_for_number(n);
	if (!result)
		return (NULL);
	length_nb = ft_intlen(n);
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[--length_nb] = ft_abs_value(n % 10) + '0';
		n /= 10;
	}
	return (result);
}
