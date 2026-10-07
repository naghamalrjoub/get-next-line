#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((len + 1) * sizeof(char));
	while (i + j < len)
	{
		if (s1[i])
		{
			str[i + j] = s1[i];
			i++;
		}
		else
		{
			str[i + j] = s2[j];
			j++;
		}
	}
	str[i + j] = '\0';
	return (str);
}
