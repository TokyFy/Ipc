/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:33:19 by franaivo          #+#    #+#             */
/*   Updated: 2024/02/22 10:29:01 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, t_size_t len)
{
	t_size_t	i;
	t_size_t	j;

	if (!*to_find)
		return ((char *)str);
	i = 0;
	j = 0;
	while (str[i] && i < len)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] && to_find[j] && i + j < len)
			{
				if (str[i + j] != to_find[j])
					break ;
				j++;
			}
			if (!to_find[j])
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
