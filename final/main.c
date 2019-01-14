/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:06:13 by jsanford          #+#    #+#             */
/*   Updated: 2019/01/14 16:16:45 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int	main(int c, char **v)
{
	int		fd;
	char	**str;
	char	*smth;

	str = &smth;
	fd = 0;
	if (c == 2)
	{
		fd = open(v[1], O_RDONLY);
		if (fd == -1)
			return (0);
		ft_putstr(*str);
		ft_putchar('\n');
	}
	else
		ft_putstr("Enter a filename.\n");
	return (0);
}
