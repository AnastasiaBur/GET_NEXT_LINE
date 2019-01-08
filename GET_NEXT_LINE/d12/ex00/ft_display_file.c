#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		main(int c, char **v)
{
	if (c == 2)
		printf("file: %s (%d)", v[1], open (v[1], O_RDONLY));
	else if (c == 1)
		printf ("File name missing");
	else
		printf("Too many arguments");
	return (0);
}
