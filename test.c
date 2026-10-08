#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("text.txt", O_RDONLY);
	char *s = get_next_line(fd);
	while (s)
	{
		printf("%s", s);
		s = get_next_line(fd);
}
	}	
	
