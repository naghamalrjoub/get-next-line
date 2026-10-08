#include <stdio.h>

#include "get_next_line.h"

int check(char *stash)
{
	int	i;

	i = 0;
	if (!ft_strlen(stash))
		return (1);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

void	copy(char **stash, char **ans)
{
	int		i;
	char	*tmp;
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	*ans = malloc(i + 1);
	ft_strlcpy(*ans, *stash, i + 1);

	tmp = ft_strdup(*stash + i);

	//printf("%s", *ans);
	free(*stash);
	*stash = tmp;
}

char	*get_next_line(int fd)
{
	char *ans;
	char *buffer;
	static char *stash;
	int c;

	buffer = malloc(BUFFER_SIZE + 1);
	c = 1;
	while (c && (!stash || check(stash)))
	{
		c = read(fd, buffer, BUFFER_SIZE);
		// printf("%d", c);
		if (c > 0)
		{
			buffer[c] = '\0';
		//	 printf("%s\n", buffer);
			stash = ft_strjoin(stash, buffer);
		//	printf("%s", stash);
		}
	//	printf("test");
	}
	// printf("stash before: %s\n", stash);
	copy(&stash, &ans);
	if (!ft_strlen(ans))
	{
		return (NULL);
	}
	//printf("stash after: %s\n answer:", stash);
	return (ans);
}
