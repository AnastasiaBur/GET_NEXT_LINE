/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:09:24 by jsanford          #+#    #+#             */
/*   Updated: 2018/12/02 16:44:09 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		i;
	int		j;
	char	*new;

	i = -1;
	if (!s2 || !s1)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(new = (char *)malloc(size)))
		return (NULL);
	while (s1[++i])
		new[i] = s1[i];
	j = i;
	i = 0;
	while (s2[i] != '\0')
	{
		new[j] = s2[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
