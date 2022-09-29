/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 02:55:20 by pszleper          #+#    #+#             */
/*   Updated: 2021/12/15 20:36:05 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	length;

	if (!lst)
		return (0);
	length = 1;
	while (lst->next != NULL)
	{
		length++;
		lst = lst->next;
	}
	return (length);
}
