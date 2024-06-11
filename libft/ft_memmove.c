/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:17:06 by franaivo          #+#    #+#             */
/*   Updated: 2024/02/22 10:29:01 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, t_size_t n)
{
	char		*to;
	const char	*from = src;
	t_size_t	i;

	to = dest;
	i = 0;
	if (from < to)
	{
		while (i++ < n)
		{
			to[n - i] = from[n - i];
		}
	}
	else if (to != from)
	{
		while (n-- != 0)
			*to++ = *from++;
	}
	return (dest);
}
