/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:43:24 by franaivo          #+#    #+#             */
/*   Updated: 2024/02/22 11:43:24 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, t_size_t len)
{
	t_size_t	l_s;
	char		*str;

	l_s = ft_strlen(s);
	if (l_s == 0 || start > l_s - 1)
		start = l_s;
	if (len > (l_s - start))
		len = l_s - start;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, (char *)(s + start), len + 1);
	return (str);
}
