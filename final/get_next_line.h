/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:51:52 by jsanford          #+#    #+#             */
/*   Updated: 2019/01/14 19:41:40 by jsanford         ###   ########.fr       */
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

# define BUFF_SIZE 99999

int		get_next_line(const int fd, char **line);

void	skip(int *i, char ***str, char *buf, int *offset);
//void	*reallocation(char **str, int len, int ret);
#endif
