#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*res;
	int		fd;
	
	fd = open("test", O_RDONLY);
	if (!fd)
	{
		printf("Error\n");
		return -1;
	}
	res = get_next_line(fd);
	printf("%s", res);
	res = get_next_line(fd);
	printf("%s", res);
	free(res);
	return (0);
}
