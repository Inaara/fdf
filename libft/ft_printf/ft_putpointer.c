/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 06:07:27 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/24 16:20:11 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putpointer(void *ptr)
{
	int	len;

	if (ptr == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	len = ft_putaddress(ptr);
	return (len + 2);
}

int	ft_putaddress(void *ptr)
{
	char				base[17];
	char				output[17];
	int					i;
	unsigned long long	converted;
	int					len;

	converted = (unsigned long long) ptr;
	ft_strlcpy(base, "0123456789abcdef", 17);
	i = 16;
	while (i-- >= 0)
	{
		output[i] = base[converted % 16];
		converted /= 16;
	}
	output[16] = '\0';
	len = ft_putstr_address(output);
	return (len);
}
