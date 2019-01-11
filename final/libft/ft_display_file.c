/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:36:30 by jsanford          #+#    #+#             */
/*   Updated: 2018/12/05 17:54:08 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_display_file(int fd)
{
	int		ret;
	char	buf[2];

	while ((ret = read(fd, buf, 1)) != 0)
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	close(fd);
}
