/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:30:58 by franaivo          #+#    #+#             */
/*   Updated: 2024/02/23 16:30:58 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	char	*ptr;

	new = ft_strdup((char *)s);
	if (!new)
		return (0);
	ptr = new;
	while (*ptr)
	{
		*ptr = f(ptr - new, *ptr);
		ptr++;
	}
	return (new);
}
