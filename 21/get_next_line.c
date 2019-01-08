/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:54:14 by jsanford          #+#    #+#             */
/*   Updated: 2018/12/27 17:50:00 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* read malloc free */

#include <stdio.h>
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{

	printf("2");
	int		i;
	printf("2");
	int		ret;
	printf("2");
	char	buf[BUFF_SIZE + 3];

	printf("2");
	if (fd == -1)
	{
		printf("open() error");
		return (0);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		i = 0;
		buf[ret] = '\0';
		while (*(buf + i))
		{
			**line = *(buf + i);
			if (*(buf + i) == '\n')
			{
				**line = '\0';
				return (0);
			}
			i++;
			line++;
		}
	}
	return (0);
}

int		main(void)
{
	char		*str;
	int			duh;
	int			fd;
	char		**fuk;

	str = (char *)malloc(sizeof(char) * 200);
	fd = open ("42", O_RDONLY);
	fuk = &str;
	printf ("fd = %d", fd);
	if (fd == -1)
	{
		printf ("open() error");
		return (1);
	}
	duh = get_next_line(fd, fuk);
	printf("works");
	return (0);
}
