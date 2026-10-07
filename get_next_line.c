#include "get_next_line.h"

int	check(char *buffer)
{
	int    i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

void	fill_buffer(char *buffer, int fd, char **lefties)
{
	int	c;

	c = read(fd, buffer, BUFFER_SIZE);
	buffer[c] = '\0';
	*lefties = ft_strjoin(*lefties, buffer);
	if (check(buffer) && c == BUFFER_SIZE)
		fill_buffer(buffer, fd, lefties);
}

char	*get_line(char **lefties)
{
    int		len;
    char	*ans;
    int		i;
    char	*tmp;

    i = 0;
    len = 0;
    while ((*lefties)[len] && (*lefties)[len] != '\n')
        len++;
    len += ((*lefties)[len] == '\n');
    ans = malloc(len + 1);
    while (i < len)
    {
		ans[i] = *lefties[i];
		i++;
	}
	ans[i] = '\0';
    tmp = malloc(ft_strlen(*lefties) - len + 1);
    i = 0;
    while ((*lefties)[len])
        tmp[i++] = (*lefties)[len++];
    tmp[i] = '\0';
    free(*lefties);
    *lefties = tmp;
    return (ans);
}

char	*get_next_line(int fd)
{
    char		buffer[BUFFER_SIZE + 1];
    static char	*lefties;

    fill_buffer(buffer, fd, &lefties);
    return (get_line(&lefties));
}
