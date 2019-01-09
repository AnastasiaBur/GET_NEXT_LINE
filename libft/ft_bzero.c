/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:05:35 by jsanford          #+#    #+#             */
/*   Updated: 2018/11/30 17:14:30 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*arr;
	unsigned int	i;

	i = 0;
	arr = s;
	if (!n)
		return ;
	while (i < n)
	{
		arr[i] = '\0';
		i++;
	}
}