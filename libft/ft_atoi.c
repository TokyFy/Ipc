/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 23:02:15 by franaivo          #+#    #+#             */
/*   Updated: 2024/02/22 10:29:01 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

int	ft_atoi(const char *str)
{
	int			value;
	int			sign;
	const char	*c;

	value = 0;
	sign = 1;
	c = str;
	while (is_space(*c))
		c++;
	if (is_sign(*c) && *c++ == '-')
		sign *= -1;
	while (ft_isdigit(*c))
	{
		value = value * 10 + (*c++ - '0');
	}
	return (value * sign);
}
