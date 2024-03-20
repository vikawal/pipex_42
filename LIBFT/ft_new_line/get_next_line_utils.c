/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:58:56 by vmyshko           #+#    #+#             */
/*   Updated: 2024/01/12 13:18:53 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <fcntl.h>	// open
#include <unistd.h> // read, write, close
#include <stdlib.h> // malloc, free
#include <stdio.h>
#include <stdint.h>

void	*ft_calloc_new(size_t nmemb, size_t size)
{
	void	*pointer;
	size_t	i;

	i = 0;
	if (nmemb > 0 && SIZE_MAX / nmemb < size)
		return (NULL);
	pointer = malloc(nmemb * size);
	if (!pointer)
		return (0);
	while (i < nmemb * size)
	{
		*((unsigned char *)pointer + i) = '\0';
		i++;
	}
	return (pointer);
}

size_t	ft_strlen_new(const char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strchr_new(const char *s, int c)
{
	unsigned char	char_c;

	char_c = (unsigned char)c;
	if (s == NULL)
		return (NULL);
	while (*s != char_c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin_new(char *s1, char *s2)
{
	char	*s3;
	size_t	counter_1;
	size_t	counter_2;

	counter_1 = -1;
	counter_2 = 0;
	if (!s1)
	{
		s1 = ft_calloc(1, sizeof(char));
		if (!s1)
			return (0);
	}
	s3 = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!s3)
		return (free(s1), NULL);
	while (s1[++counter_1] != '\0')
		s3[counter_1] = s1[counter_1];
	while (s2[counter_2] != '\0')
	{
		s3[counter_1 + counter_2] = s2[counter_2];
		counter_2++;
	}
	s3[counter_1 + counter_2] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strdup_new(char *s)
{
	size_t	len;
	char	*dup;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}
