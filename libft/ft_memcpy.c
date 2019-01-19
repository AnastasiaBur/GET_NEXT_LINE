/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:07:54 by jsanford          #+#    #+#             */
/*   Updated: 2018/12/05 17:17:13 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned int		i;

	i = 0;
	d = s1;
	s = s2;
	if (s1 == s2)
		return (s1);
	if (n)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (s1);
}
