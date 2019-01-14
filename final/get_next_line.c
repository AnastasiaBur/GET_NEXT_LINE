/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 20:04:18 by jsanford          #+#    #+#             */
/*   Updated: 2019/01/14 19:41:55 by jsanford         ###   ########.fr       */
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

	printf ("\nBeginning\n");
	i = 0;
	len = 0;
	i = lseek(fd, offset, SEEK_SET);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		i = len;
		//str = reallocation(str, len, ret);
		len += ret;
		*str = (char*)malloc(len);
		printf("\n Before: i = %d, str = %s, buf = %s, offset = %d", i, *str, buf, offset);
		skip(&i, &str, buf, &offset);
		printf("\n After: i = %d, str = %s, buf = %s, offset = %d", i, *str, buf, offset);
		if (buf[i] == '\n')
		{
			printf("return(1)");
			offset++;
			return (1);
		}	
	}
	if (ret <= 0 || buf[i] == EOF)
	{
		offset = 0;
		return (0);
	}
	return (1);
}

void	skip(int *i, char ***str, char *buf, int *offset)
{
	char	*adr;

	adr = **str;
	while (buf[*i] != '\n' && buf[*i] != EOF && *i < BUFF_SIZE)
	{
		printf("\n1 i=%d str= %s", *i, **str);
		*adr = buf[*i];
		printf("\n2 i=%d str= %s", *i, **str);
		*i += 1;
		*offset += 1;
		adr++;
		printf("\n3 i=%d str= %s", *i, **str);
	}
}

void	*reallocation(char ***str, int len, int ret)
{
	char	*new;
	int		i = 0;

	new = (char*)ft_memalloc(sizeof(char) * (len + ret));
	if (len > 0)
	{
		new = ft_memcpy(new, *str, len);
		free(str);
	}
	return (new);
}
