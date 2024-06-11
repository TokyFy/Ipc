/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:15:25 by franaivo          #+#    #+#             */
/*   Updated: 2024/02/23 15:15:25 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_digit(int n)
{
	if (n < 0)
		return (1 + count_digit(-n));
	if (n <= 9)
		return (1);
	return (1 + count_digit(n / 10));
}

char	*ft_itoa(int i)
{
	int		n;
	int		digit;
	char	*str;

	if (i == -2147483648)
		return (ft_strdup("-2147483648"));
	n = i;
	digit = count_digit(n);
	str = 0;
	str = ft_calloc(digit + 1, sizeof(char));
	if (!str)
		return (0);
	if (n < 0)
		n = -n;
	while (digit > 0)
	{
		*(str + digit - 1) = (n % 10) + '0';
		n = n / 10;
		digit--;
	}
	if (i < 0)
		*str = '-';
	return (str);
}
