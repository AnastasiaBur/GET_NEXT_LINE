#include <stdio.h>

void	test(void)
{
	static int x = 0; 
	x++;
	printf("%d\n", x);
}
