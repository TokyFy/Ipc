/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:41:11 by franaivo          #+#    #+#             */
/*   Updated: 2024/02/22 10:29:01 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, t_size_t n)
{
	unsigned char	chr;
	unsigned char	*str;
	t_size_t		i;

	str = (unsigned char *)s;
	i = 0;
	chr = c;
	while (i < n)
	{
		if (str[i] == chr)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}
