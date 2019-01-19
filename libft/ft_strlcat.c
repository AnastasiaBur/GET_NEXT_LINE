/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:07:54 by jsanford          #+#    #+#             */
/*   Updated: 2018/12/05 17:17:14 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	n;

	j = 0;
	i = ft_strlen(dst);
	n = ft_strlen(src);
	if (size < i + 1)
		return (size + n);
	while (src[j] != '\0' && i < size - 1 && size > 1)
	{
		dst[i] = src[j];
		i++;
		j++;
		n--;
	}
	dst[i] = '\0';
	return (i + n);
}
