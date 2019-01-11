#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int		main()
{
	int		i;
	char	fst[] = "Testing, testing!";
	char	*str, *str1;
	char	**snd;

	snd = &str;
	*snd = (char *)malloc(50 * sizeof (char));
	str1 = *snd;
	while (fst[i] != '!')
	{
		*str1 = fst[i];
		str1++;
		i++;
	}
	printf("%s", *snd);
	return (0); 
}
