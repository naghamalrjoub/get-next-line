/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalrjoub <nalrjoub@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 11:48:26 by nalrjoub          #+#    #+#             */
/*   Updated: 2026/10/10 11:51:42 by nalrjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check(char *stash)
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

char	*get_stash(char *stash, int fd)
{
	char	*buffer;
	int		c;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free_strings(&stash, &buffer));
	c = 1;
	while (c && check(stash))
	{
		c = read(fd, buffer, BUFFER_SIZE);
		if (c > 0)
		{
			buffer[c] = '\0';
			stash = ft_strjoin(stash, buffer);
			if (stash == NULL)
				return (NULL);
		}
		if (c < 0)
			return (free_strings(&stash, &buffer));
	}
	free(buffer);
	return (stash);
}

void	trim_stash(char **stash, int i)
{
	char	*tmp;

	tmp = ft_strdup(*stash + i);
	free(*stash);
	*stash = tmp;
}

char	*get_line(char **stash)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	tmp = malloc(i + 1);
	if (!tmp)
		return (free_strings(stash, &tmp));
	ft_strlcpy(tmp, *stash, i + 1);
	trim_stash(stash, i);
	if (!*stash)
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*ans;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_stash(stash, fd);
	if (!stash)
		return (NULL);
	ans = get_line(&stash);
	if (!ft_strlen(ans))
		return (free_strings(&ans, &stash));
	return (ans);
}
