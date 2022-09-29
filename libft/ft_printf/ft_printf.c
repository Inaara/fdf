/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:24:44 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/24 16:20:04 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_pick_printer_function(const char *str, int i, int *len, va_list args)
{
	if (str[i + 1] == 'c')
		*len += ft_putchar(va_arg(args, int));
	else if (str[i + 1] == 's')
		*len += ft_putstr(va_arg(args, char *));
	else if (str[i + 1] == 'p')
		*len += ft_putpointer(va_arg(args, void *));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		*len += ft_putnbr(va_arg(args, int));
	else if (str[i + 1] == 'u')
		*len += ft_putnbr_unsigned(va_arg(args, unsigned long long));
	else if (str[i + 1] == 'x')
		*len += ft_puthex_lower(va_arg(args, int));
	else if (str[i + 1] == 'X')
		*len += ft_puthex_upper(va_arg(args, int));
	else if (str[i + 1] == '%')
		*len += ft_putchar('%');
}

int	ft_printf(const char *format, ...)
{
	va_list	argsptr;
	int		i;
	int		printed_chars;

	va_start(argsptr, format);
	i = 0;
	printed_chars = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_pick_printer_function(format, i, &printed_chars, argsptr);
			i += 2;
		}
		else
		{
			write(1, &format[i++], 1);
			printed_chars++;
		}
	}
	va_end(argsptr);
	return (printed_chars);
}
