/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:05:35 by jsanford          #+#    #+#             */
/*   Updated: 2019/01/08 18:14:47 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	putstr_fd(int fd, const char *str)
{
	while (*str != '\0')
		write(fd, str++, 1); 
}

int	main(int c, char **v)
{
	int fd;

	fd = 0;
	if (c == 2)
	{
		fd = open (v[1], O_WRONLY | O_CREAT| O_APPEND, S_IRUSR | S_IWUSR);
		printf("file: %s (%d)", v[1], fd);
		putstr_fd(fd, "?&&&\n");
		printf ("\n\n close (fd) :  %d", close(fd));
	}
	else if (c == 1)
		printf ("File name missing");
	else
		printf("Too many arguments");
	return (0);
}

