#include "get_next_line.h"
#include <stdio.h>

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

void	*free_strings(char **stash, char **ans, char **buffer)
{
	free(*ans);
	free(*stash);
	free(*buffer);
	*ans = NULL;
	*stash = NULL;
	*buffer = NULL;
	return (NULL);
}

void	copy(char **stash, char **ans, char **buffer)
{
	int		i;
	char	*tmp;

	i = 0;
	if (*stash) 
	{
		while ((*stash)[i] && (*stash)[i] != '\n')
			i++;
		if ((*stash)[i] == '\n')
			i++;
		*ans = malloc(i + 1);
		if (!ans)
		{
			ans = NULL;
			return ;
		}
		ft_strlcpy(*ans, *stash, i + 1);
		tmp = ft_strdup(*stash + i);
		free(*stash);
		*stash = tmp;
	}
}

int	allocate_buffer(char **buffer)
{
	*buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	char *ans;
	char *buffer;
	static char *stash;
	int c;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	c = allocate_buffer(&buffer);
	while (c && (!stash || check(stash)))
	{
		c = read(fd, buffer, BUFFER_SIZE);
		if (c > 0)
		{
			buffer[c] = '\0';
			stash = ft_strjoin(stash, buffer);
		}
		else if (c < 0)
			return (free_strings(&stash, &ans, &buffer));
	}
	copy(&stash, &ans, &buffer);
	if (!ft_strlen(ans))
		return(free_strings(&stash, &ans, &buffer));
	free(buffer);
	return (ans);
}
