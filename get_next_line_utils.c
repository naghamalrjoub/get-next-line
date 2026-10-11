/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalrjoub <nalrjoub@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 11:50:31 by nalrjoub          #+#    #+#             */
/*   Updated: 2026/10/10 11:51:01 by nalrjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !size || !src)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(char *s)
{
	int		len;
	int		i;
	char	*str;

	len = ft_strlen(s);
	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*free_strings(char **s1, char **s2)
{
	free(*s1);
	free(*s2);
	*s1 = NULL;
	*s2 = NULL;
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = malloc((i + j + 1) * sizeof(char));
	if (!str)
		return (free_strings(&s1, &s2));
	if (s1)
		ft_strlcpy(str, s1, i + 1);
	ft_strlcpy(str + i, s2, j + 1);
	free(s1);
	str[i + j] = '\0';
	return (str);
}

