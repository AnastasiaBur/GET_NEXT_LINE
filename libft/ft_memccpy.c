/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:07:54 by jsanford          #+#    #+#             */
/*   Updated: 2018/12/05 17:17:13 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char	*d;
	size_t	i;

	i = 0;
	d = s1;
	if (n)
	{
		while (i < n)
		{
			d[i] = *((unsigned char *)s2 + i);
			if (*((unsigned char *)s2 + i) == (unsigned char)c)
				return (s1 + i + 1);
			i++;
		}
	}
	return (NULL);
}
