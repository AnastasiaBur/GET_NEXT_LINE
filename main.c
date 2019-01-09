/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:05:35 by jsanford          #+#    #+#             */
/*   Updated: 2019/01/09 18:46:30 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "head.h"

int	main(int c, char **v)
{
	int		fd;
	int		i;
	char	**str;

	str = NULL;
	fd = 0;
	i = 0;
	if (c == 2)
	{
		while (i < 20)
		{
			fd = open(v[1], O_RDONLY);
			if (fd == -1)
			{
				ft_putstr_fd("\nopen() error", 2);
				return (0);
			}
			if ((get_next_line(fd, str)) == -1)
				ft_putstr("error");
		//	ft_putstr(*str);
			i++;
		}
	}
	else if (c == 1)
		ft_putstr("File name missing\n");
	else
		ft_putstr("Too many arguments\n");
	return (0);
}
