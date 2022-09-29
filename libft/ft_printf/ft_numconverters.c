/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numconverters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 02:29:25 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/24 16:19:58 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr(int n)
{
	char	current_converted;
	int		returned;

	returned = ft_intlen(n);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (returned);
	}
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n <= 9)
	{
		current_converted = n + '0';
		write(1, &current_converted, 1);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (returned);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	current_converted;
	int		returned;

	returned = ft_unsigned_intlen(n);
	if (n <= 9)
	{
		current_converted = n + '0';
		write(1, &current_converted, 1);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (returned);
}

int	ft_unsigned_intlen(unsigned int n)
{
	int					length_nb;
	unsigned long		divider;

	if (n == 0)
		return (1);
	length_nb = 11;
	divider = 10000000000;
	while (n / divider == 0 && length_nb > 0)
	{
		length_nb--;
		divider /= 10;
	}
	return (length_nb);
}
