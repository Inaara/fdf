/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:26:03 by pszleper          #+#    #+#             */
/*   Updated: 2021/12/16 00:08:01 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last_element;

	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	last_element = ft_lstlast(*alst);
	last_element->next = new;
}
