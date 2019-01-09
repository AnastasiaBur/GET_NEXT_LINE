/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:54:14 by jsanford          #+#    #+#             */
/*   Updated: 2019/01/09 18:46:05 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* read malloc free */

#include "head.h"

int		get_next_line(const int fd, char **str)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	int			i;	
	static int	offset = 0;

	i = 0;
	if ((lseek(fd, offset, SEEK_SET)) == -1)
	{
		ft_putstr("lseek() error");
		return (close(fd));
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		i = 0;
		while (buf[i] != '\n' && buf[i] != '\0' && i < BUFF_SIZE)
		{
			if (str)
			{}
		//	str = (char **)malloc(sizeof(str) * ret);
		//	ft_strcpy(*str, "Hey");
			ft_putchar(buf[i]);
			i++;
			offset++;
		}
		if (buf[i] == '\n' || buf[i] == '\0')
		{
			if (buf[i] == '\n')
				offset++;
			ft_putchar('\n');
			return (close(fd));
		}
	}
	offset = 0;
	return (close(fd));
}
