/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:07:54 by jsanford          #+#    #+#             */
/*   Updated: 2018/12/05 17:17:14 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	while (s && *s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
