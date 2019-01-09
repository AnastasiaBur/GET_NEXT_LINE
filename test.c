#include "libft.h"

void	test(void)
{
	static int x = 0; 
	x++;
	ft_putnbr(x);
	ft_putchar('\n');
}
