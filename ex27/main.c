/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 08:55:13 by lsimon            #+#    #+#             */
/*   Updated: 2016/11/03 14:06:07 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "display_file.h"
#include <stdio.h>

void	ft_display_file(int f)
{
	char	buff[BUFF_SIZE + 1];
	int		r;

	while ((r = read(f, buff, BUFF_SIZE)))
	{
		buff[r] = '\0';
		write(1, buff, 1);
	}
}

int		main(int argc, char **argv)
{
	int		f;

	if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	f = open(argv[1], O_RDONLY);
	ft_display_file(f);
	return (0);
}
