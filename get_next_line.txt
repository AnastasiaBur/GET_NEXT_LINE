/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:28:27 by jsanford          #+#    #+#             */
/*   Updated: 2019/01/19 18:02:00 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_reading(int const fd, char **crnt)
{
	char	buf[BUFF_SIZE + 1];//buffer with and added place for '\0'
	int		read_return;
	char	*new_crnt;

	read_return = read(fd, buf, BUFF_SIZE);
//	if we've read anything
	if (read_return > 0)
	{
//		we put an '\0' in the end of the string we've read
		buf[read_return] = '\0';
//		we concatenate our current buffer and the newly read bytes
		if (!(new_crnt = ft_strjoin(*crnt, buf)))
			return (-1);// and check if it worked
//		then we free crnt since we already have a copy of it in newcrnt
		free(*crnt);
		*crnt = new_crnt;
	}
	return (read_return);
}

int		get_next_line(int const fd, char **str)
{
	int			read_return;
	static char	*crnt = NULL;// our CURRENT buffer
	char		*end_symbol;// the adress of a symbol we're looking for

//	if (this is a new line) and (malloc failed to allocate memory)
	if ((crnt == NULL) && ((crnt = (char*)ft_memalloc(sizeof(char))) == NULL))
		return (-1);//				also we allocate a memory slot for crnt
//	search for a '\n' in our buffer
	end_symbol = ft_strchr(crnt, '\n');
//	while we haven't found one
	while (end_symbol == NULL)
	{
//		if we've reached the end of the file
		if ((read_return = ft_reading(fd, &crnt)) == 0)
		{
//		this is important: 
//		we set end_symbol's adress to the adress of '\0'
//		so we will break the cicle (since we've reached the end of the file)
//		if there is anything in our buffer we must return (1) after the cicle
//		and if the file ends with '\n', our current buffer will start with '\0'
//		in this case we immediately return (0)
			if ((end_symbol = ft_strchr(crnt, '\0')) == crnt)
				return (0);
		}
//				if read returned an error, we return an error
		else if (read_return < 0)
			return (-1);
		else//	keep searching for the '\n'
			end_symbol = ft_strchr(crnt, '\n');
	}
//		we put a substring of crnt (from the first symbol to '\n' into str
	if (!(*str = ft_strsub(crnt, 0, end_symbol - crnt)))
		return (-1);// and check that we've done that successfully
//	we skip one symbol ('\n') so the next reading won't start with it
	end_symbol = ft_strdup(end_symbol + 1);
//	we free our crnt since we finished working with it
	free(crnt);
//	and put the string that starts after '\n' into it
	crnt = end_symbol;
	return (1);
}
