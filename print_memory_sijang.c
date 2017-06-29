/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory_sijang.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sijang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 21:45:31 by sijang            #+#    #+#             */
/*   Updated: 2017/01/12 22:16:15 by sijang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char c)
{
	unsigned char	h;
	char			*nb = "0123456789abcdef";

	h = nb[c % 16];
	c /= 16;
	write(1, &nb[c % 16], 1);
	write(1, &h, 1);
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char	*bytes;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	bytes = (unsigned char *)addr;
	while (i < size)
	{
		print_hex(bytes[i]);
		if (++i % 2 == 0)
			write(1, " ", 1);
		if (i % 16 == 0)
		{
			while (j < i)
			{
				if (32 <= bytes[j] && bytes[j] < 127)
					write(1, &bytes[j], 1);
				else
					write(1, ".", 1);
				j++;
			}
			write(1, "\n", 1);
		}
	}
	while (i % 16)
	{
		write(1, "  ", 2);
		if (++i % 2 == 0)
			write(1, " ", 1);
		if (i % 16 == 0)
		{
			while (j++ < size)
				write(1, ".", 1);
			write(1, "\n", 1);
		}
	}
}
