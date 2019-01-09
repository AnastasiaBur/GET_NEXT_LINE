/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:05:35 by jsanford          #+#    #+#             */
/*   Updated: 2018/11/30 17:10:34 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*arr;

	i = 0;
	arr = s;
	if (n)
	{
		while (i < n)
		{
			arr[i] = (unsigned char)c;
			i++;
		}
	}
	return (s);
}
