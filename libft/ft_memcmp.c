/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:05:24 by jsanford          #+#    #+#             */
/*   Updated: 2018/12/02 15:17:11 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*fir;
	const unsigned char	*sec;
	unsigned int		i;

	i = 0;
	fir = s1;
	sec = s2;
	while (i < n && fir[i] == sec[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)fir[i] - (unsigned char)sec[i]);
}
