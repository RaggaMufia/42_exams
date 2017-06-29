/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sijang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:08:43 by sijang            #+#    #+#             */
/*   Updated: 2016/12/05 21:54:20 by sijang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	tap[30000] = {0};
unsigned char	*ptr = tap;

void	interpret(char *str)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c == '>')
			++ptr;
		else if (c == '<')
			--ptr;
		else if (c == '+')
			++*ptr;
		else if (c == '-')
			--*ptr;
		else if (c == '.')
			write(1, ptr, 1);
		else if (c == ']' && *ptr)
		{
			j = 1;
			while (j > 0)
			{
				c = str[--i];
				if (c == '[')
					j--;
				else if (c == ']')
					j++;
			}
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		interpret(argv[1]);
	return (0);
}
	
