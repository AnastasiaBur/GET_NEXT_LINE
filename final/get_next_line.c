/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 20:04:18 by jsanford          #+#    #+#             */
/*   Updated: 2019/01/11 20:07:32 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **str)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	int			i;
	static int	offset = 0;
	int			len;

	i = 0;
	len = 0;
	if ((lseek(fd, offset, SEEK_SET)) == -1)
	{
		close(fd);
		return (-1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		len += ret;
		*str = (char *)malloc(sizeof(char) * (len + 1));
		skip(&i, &str, buf, &offset);
		if (buf[i] == '\n' || buf[i] == '\0')
			return (close(fd));
	}
	offset = 0;
	return (close(fd));
}

void	skip(int *i, char ***str, char *buf, int *offset)
{
	char	*adr;

	adr = **str;
	*i = 0;
	while (buf[*i] != '\n' && buf[*i] != '\0' && *i < BUFF_SIZE)
	{
		*adr = buf[*i];
		*i += 1;
		*offset += 1;
		adr++;
	}
	if (buf[*i] == '\n')
		*offset += 1;
}
