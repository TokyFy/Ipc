/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:58:06 by franaivo          #+#    #+#             */
/*   Updated: 2024/02/23 10:58:06 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	t_size_t	start;
	t_size_t	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]))
	{
		start++;
	}
	while (ft_strchr(set, s1[end]))
	{
		end--;
	}
	return (ft_substr(s1, start, end - start + 1));
}
