/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 02:58:38 by pszleper          #+#    #+#             */
/*   Updated: 2021/12/15 20:42:08 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_element_ptr;

	if (!lst)
		return (NULL);
	last_element_ptr = lst;
	while (last_element_ptr->next != NULL)
	{
		last_element_ptr = last_element_ptr->next;
	}
	return (last_element_ptr);
}
