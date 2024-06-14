/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:44:59 by bmoretti          #+#    #+#             */
/*   Updated: 2024/06/14 13:24:27 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

unsigned char	read_bin(const char * bits)
{
	short int		i = 0;
	unsigned char	c = 0;

	while (i < 8)
	{
		if (bits[i] == '1')
		{
			c = c | 1 << (7 - i);
		}
		i++;
	}
	return (c);
}

char	switch_last_bits(unsigned char c)
{
	const unsigned char	last_bits = c & 3;
	const unsigned char	first_six_bits = c & 252;
	const unsigned char	\
	swiched_bits = ((last_bits & 1) << 1) | ((last_bits & 2) >> 1);

	return (first_six_bits | swiched_bits);
}

char	switch_four_bits(unsigned char c)
{
	const unsigned char first_half = c & 240;
	const unsigned char last_half = c & 15;

	return (first_half >> 4 | last_half << 4);
}

int	main(void)
{
	char	c;
	int		file = open("message.txt", O_RDONLY);
	if (!file)
	{
		return (1);
	}
	char	*line = malloc(9);
	if (!line)
	{
		return(1);
	}

	while (read(file, line,))
	{
		c = read_bin(line);
		c = switch_last_bits(c);
		c = switch_four_bits(c);
		write(1, &c, 1);
	}
	free(line);

	return (0);
}
