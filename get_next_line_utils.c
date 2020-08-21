/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hovalygtaraa <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 09:55:46 by hovalygta         #+#    #+#             */
/*   Updated: 2020/07/19 00:34:18 by hovalygta        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *string)
{
	size_t		i;

	if (!string)
		return (0);
	i = 0;
	while (string[i] != 0)
	{
		i++;
	}
	return (i);
}

void	*ft_line_calloc(size_t count, size_t size)
{
	size_t			a;
	size_t			i;
	unsigned char	*b;

	i = 0;
	a = (count * size);
	if (!(b = malloc(a + 1)))
		return (NULL);
	b[a] = '\0';
	return (b);
}

char	*ft_strchr(char *s, int c)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return (&s[i]);
		}
		i++;
	}
	return (NULL);
}

char	*sad_strjoin(char *s)
{
	size_t	a;
	size_t	i;
	char	*s3;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if ((s3 = ft_line_calloc(i, sizeof(char))) == NULL)
		return (NULL);
	a = -1;
	while (s[++a] != 0)
		s3[a] = s[a];
	s3[a] = '\0';
	return (s3);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		a;
	size_t		b;
	char		*s3;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (sad_strjoin(s2));
	if (!s2)
		return (sad_strjoin(s1));
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if ((s3 = ft_line_calloc(a + b, sizeof(char))) == NULL)
		return (NULL);
	a = -1;
	b = -1;
	while (s1[++a] != 0)
		s3[a] = s1[a];
	while (s2[++b] != 0)
		s3[a + b] = s2[b];
	s3[a + b] = '\0';
	free(s1);
	s1 = NULL;
	return (s3);
}
