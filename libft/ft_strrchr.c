/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:45:16 by franaivo          #+#    #+#             */
/*   Updated: 2024/02/22 10:29:01 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	t_size_t	lstr;
	char		chr;

	lstr = ft_strlen(s);
	chr = c;
	while (lstr > 0)
	{
		if (*(s + lstr) == chr)
			return ((char *)(s + lstr));
		lstr--;
	}
	if (*s == chr)
		return ((char *)s);
	return (0);
}
