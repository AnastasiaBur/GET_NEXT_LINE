#include "head.h"

int		get_next_line(const int fd, char **str)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	int			i;
	static int	offset = 0;
	int			len;
	char		*adr;

	i = 0;
	len = 0;
	if ((lseek(fd, offset, SEEK_SET)) == -1)
	{
		close(fd)
		return (-1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		len += ret;
		*str = (char *)malloc(sizeof(char) * (len + 1));
		adr = *str;
		i = 0;
		while (buf[i] != '\n' && buf[i] != '\0' && i < BUFF_SIZE)
		{
			*adr = buf[i];
			i++;
			offset++;
			adr++;
		}
		if (buf[i] == '\n' || buf[i] == '\0')
		{
			if (buf[i] == '\n')
				offset++;
			return (close(fd));
		}
	}
	offset = 0;
	return (close(fd));
}
