#include "get_next_line.h"

int check(char *stash)
{
	int	i;

	i = 0;
	if (!ft_strlen(stash))
		return (0);
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
	(*ans) = malloc(i + 1);
	ft_strlcpy(*ans, *stash, i + 1);
	tmp = ft_strdup((*stash) + i);
	free(*stash);
	*stash = tmp;
	free(tmp);
}

char	*get_next_line(int fd)
{
	char *ans;
	char buffer[BUFFER_SIZE + 1];
	static char *stash;
	int c;

	while (!stash || check(stash))
	{
		c = read(fd, buffer, BUFFER_SIZE);
		if (c > 0)
		{
			buffer[c] = '\0';
			stash = ft_strjoin(stash, buffer);	
		}
	}
	copy(&stash, &ans);
	return (ans);
}
