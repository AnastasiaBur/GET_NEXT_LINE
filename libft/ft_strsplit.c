/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:13:46 by jsanford          #+#    #+#             */
/*   Updated: 2018/11/30 20:28:18 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		getlen(char const *str, char c)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		l++;
	}
	return (l);
}

static int		words(char const *str, char c)
{
	int words;
	int	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**new;

	if (!s)
		return (NULL);
	if (!(new = (char **)malloc(sizeof(*new) * (words(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < words(s, c))
	{
		k = 0;
		if (!(new[i] = ft_strnew(getlen(&s[j], c) + 1)))
		{
			ft_strdel(new);
			return (NULL);
		}
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			new[i][k++] = s[j++];
		new[i][k] = '\0';
		i++;
	}
	new[i] = 0;
	return (new);
}
