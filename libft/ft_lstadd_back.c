/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:45:02 by franaivo          #+#    #+#             */
/*   Updated: 2024/02/24 15:45:02 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *el)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = el;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = el;
}
