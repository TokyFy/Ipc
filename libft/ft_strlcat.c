/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:47:07 by franaivo          #+#    #+#             */
/*   Updated: 2024/02/22 10:29:01 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	t_size_t	ldest;
	t_size_t	lsrc;

	ldest = ft_strlen(dest);
	lsrc = ft_strlen(src);
	if (ldest >= size)
		return (size + lsrc);
	return (ldest + ft_strlcpy(dest + ldest, src, size - ldest));
}
