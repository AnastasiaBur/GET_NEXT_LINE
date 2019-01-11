#include "libft.h"
#include "head.h"

int	main(int c, char **v)
{
	int		fd;
	int		i;
	char	**str;
	char	*smth;

	str = &smth;
	fd = 0;
	i = 0;
	if (c == 2)
	{
		while (i < 6)
		{
			fd = open(v[1], O_RDONLY);
			if (fd == -1)
				return (0);
			if ((get_next_line(fd, str)) == -1)
				ft_putstr("error");
			ft_putstr(*str);
			i++;
			ft_putchar('\n');
		}
	}
	else if (c == 1)
		ft_putstr("File name missing\n");
	else
		ft_putstr("Too many arguments\n");
	return (0);
}
