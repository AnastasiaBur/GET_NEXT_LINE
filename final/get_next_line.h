/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:51:52 by jsanford          #+#    #+#             */
/*   Updated: 2019/01/16 19:42:13 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>

# define BUFF_SIZE 4000

int		get_next_line(const int fd, char **line);

void	skip(int *i, char ***str, const char *buf, int *offset);
char	**ft_realloc(char **str, int len, int ret);
#endif
