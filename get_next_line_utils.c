/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 10:05:06 by fgomez            #+#    #+#             */
/*   Updated: 2021/02/03 11:05:44 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char		*ft_strnew(size_t size)
{
	return (ft_malloc((size + 1) * sizeof(char)));
}

void		*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ch;

	ch = (unsigned char*)b;
	while (len)
	{
		*ch = (unsigned char)c;
		ch++;
		len--;
	}
	return (b);
}

int			ft_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
