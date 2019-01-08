/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:05:34 by jsanford          #+#    #+#             */
/*   Updated: 2018/12/02 15:13:54 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	unsigned int	i;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (len == 0)
		return (dst);
	if (dst == src)
		return (dst);
	if (s < d)
	{
		len--;
		while ((int)len >= 0)
		{
			d[len] = s[len];
			len--;
		}
	}
	else
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	return (dst);
}
