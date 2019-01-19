/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:28:27 by jsanford          #+#    #+#             */
/*   Updated: 2019/01/19 17:05:26 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_reading(int const fd, char **crnt)
{
	char	buf[BUFF_SIZE + 1];
	int		bytes;
	char	*join;

	bytes = read(fd, buf, BUFF_SIZE);
	if (bytes > 0)
	{
		buf[bytes] = '\0';
		if (!(join = ft_strjoin(*crnt, buf)))
			return (-1);
		free(*crnt);
		*crnt = join;
	}
	return (bytes);
}

int		get_next_line(int const fd, char **str)
{
	int			ret;
	static char	*crnt = NULL;
	char		*end_symbol;

	if ((crnt == NULL) && ((crnt = (char*)ft_memalloc(sizeof(char))) == NULL))
		return (-1);
	end_symbol = ft_strchr(crnt, '\n');
	while (end_symbol == NULL)
	{
		if ((ret = ft_reading(fd, &crnt)) == 0)
		{
			if ((end_symbol = ft_strchr(crnt, '\0')) == crnt)
				return (0);
		}
		else if (ret < 0)
			return (-1);
		else
			end_symbol = ft_strchr(crnt, '\n');
	}
	if (!(*str = ft_strsub(crnt, 0, end_symbol - crnt)))
		return (-1);
	end_symbol = ft_strdup(end_symbol + 1);
	free(crnt);
	crnt = end_symbol;
	return (1);
}
