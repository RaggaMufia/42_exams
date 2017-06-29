/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 10:43:03 by exam              #+#    #+#             */
/*   Updated: 2016/12/20 10:55:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	int		tmp;
	char	*arr;
	int		len;
	char	nb[] = "0123456789ABCDEF";

	if (!value || base < 2 || 16 < base)
		return ("0");
	if (value == -2147483648 && base == 10)
		return ("-2147483648");
	if (value < 0 && base != 10)
		value = -value;
	tmp = (value < 0) ? -value : value;
	len = (value < 0) ? 2 : 1; 
	while (tmp > base - 1)
	{
		tmp /= base;
		len++;
	}
	arr = (char *)malloc(sizeof(char) * (len + 1));
	arr[len] = '\0';
	tmp = (value < 0) ? -value : value;
	while (tmp && len--)
	{
		arr[len] = nb[tmp % base];
		tmp /= base;
	}
	if (value < 0)
		arr[0] = '-';
	return (arr);
}
