/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 20:04:18 by jsanford          #+#    #+#             */
/*   Updated: 2019/01/16 19:39:00 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **str)
{
	char		buf[BUFF_SIZE];
	int			i;
	static int	offset = 0;
	int			len;
	int			ret;

	i = 0;
	len = 0;
	if (fd < 0)
		return (-1);
	i = lseek(fd, offset, SEEK_SET);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		i = len;
		if (len < 1)
			*str = (char*)ft_memalloc(len + ret);
		else
			str = ft_realloc(str, len, ret);
		len += ret;
		skip(&i, &str, buf, &offset);
		if (buf[i] == '\n')
		{
			offset++;
			return (1);
		}
	}
	if (ret == 0 || buf[i] == EOF)
	{
		offset = 0;
		return (0);
	}
	if (ret < 0)
		return (-1);
	return (1);
}

void	skip(int *i, char ***str, const char *buf, int *offset)
{
	char	*adr;

	adr = **str;
	while (buf[*i] != '\n' && buf[*i] != EOF && *i < BUFF_SIZE)
	{
		*adr = buf[*i];
		*i += 1;
		adr++;
		*offset += 1;
	}
}

char	**ft_realloc(char **str, int len, int ret)
{
	char	**new;
	char	*idk;

	new = &idk;
	*new = (char*)ft_memalloc(sizeof(char) * (len + ret));
	if (len > 0)
	{
		*new = ft_memcpy(new, str, len);
		//ft_memdel((void**)str);
	}
	return (new);
}
