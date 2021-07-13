/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 09:35:29 by fgomez            #+#    #+#             */
/*   Updated: 2021/02/20 11:22:45 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char		*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = -1;
	while (src[++i])
		;
	if (!(dest = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = -1;
	while (src[++i] != '\0')
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char		*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!(str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	str[0] = '\0';
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

int			get_next_line(int fd, char **line)
{
	ssize_t		ret;
	char		buff[BUFFER_SIZE + (ret = 1)];
	static char	*str[FD_SIZE];
	char		*tmp;

	if (fd < 0 || fd >= 256 || !line || BUFFER_SIZE <= 0)
		return (-1);
	str[fd] == NULL ? str[fd] = ft_strnew(0) : NULL;
	while (!ft_strchr(str[fd], '\n') && (ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(str[fd], buff);
		ft_free(&str[fd]);
		str[fd] = tmp;
	}
	if (ret == 0)
		*line = ft_strdup(str[fd]);
	else if (ret > 0)
		*line = ft_substr(str[fd], 0, (ft_strchr(str[fd], '\n') - str[fd]));
	else
		return (-1);
	tmp = ft_strdup(str[fd] + (ft_strlen(*line) + ((ret > 0) ? +1 : +0)));
	ft_free(&str[fd]);
	str[fd] = tmp;
	return (ret == 0 ? 0 * ft_free(&str[fd]) : 1);
}
