/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:44:56 by franaivo          #+#    #+#             */
/*   Updated: 2024/02/24 15:44:56 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*new;
	void	*content;

	new = 0;
	while (lst)
	{
		content = f(lst->content);
		map = ft_lstnew(content);
		if (!map)
		{
			free(content);
			ft_lstclear(&new, (*del));
			return (0);
		}
		ft_lstadd_back(&new, map);
		lst = lst->next;
	}
	return (new);
}
