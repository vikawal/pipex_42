/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:26:20 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/25 14:58:57 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	count_substrings(char const *str, char c)
{
	size_t		num_substrings;

	num_substrings = 0;
	while (*str != '\0')
	{
		if (*str != c)
		{
			num_substrings++;
			while (*str != '\0' && *str != c)
				str++;
		}
		else
			str++;
	}
	return (num_substrings);
}
// int main ()
// {
// 	char a[] = ",,,,,Hello,World,Split,HA";
// 	printf("Result %d\n", count_substrings(a, ','));
// }

static void	**free_mem_substrings(char **substrings, int i)
{
	while (i > 0)
	{
		i--;
		free(substrings[i]);
	}
	return (0);
}

static size_t	substr_len(const char *s, char c)
{
	size_t		len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static char	*process_substr(char **result, const char *s, size_t i, char c)
{
	const char	*start;
	size_t		len;

	start = s;
	len = substr_len(s, c);
	s = s + len;
	result[i] = ft_substr(start, 0, len);
	if (!result[i])
	{
		free_mem_substrings(result, i);
		free(result);
		return (NULL);
	}
	return ((char *)s);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_substrings(s, c) + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			s = process_substr(result, s, i, c);
			if (!s)
				return (NULL);
			i++;
		}
		else
			s++;
	}
	result[i] = (NULL);
	return (result);
}
// int	main()
// {
// 	char	str[] = "Hello, World ,,,!";
// 	char	c = ' ';
// 	char	**spt = ft_split(str, c);
// 	int	i = 0;
// 	while (spt[i] != 0)
// 	{
// 		ft_putstr_fd(spt[i], 1);
// 		free(spt[i]); //free memory of each substring
// 		i++;
// 	}
// 	ft_putchar_fd('\n', 1); 
// 	free(spt); // free pointer

// }
//ALSO WORKS, NO FREE MEMORY
// static int	count_substring(char const *str, char c)
// {
// 	size_t		num_substring;

// 	num_substring = 0;
// 	while (*str != '\0')
// 	{
// 		if (*str != c)
// 		{
// 			num_substring++;
// 			while (*str != '\0' && *str != c)
// 				str++;
// 		}
// 		else
// 			str++;
// 	}
// 	return (num_substring);
// }

// char	**ft_split(const char *s, char c)
// {
// 	char	**result;
// 	size_t	i;
// 	size_t	len;

// 	if (!s)
// 		return (0);
// 	i = 0;
// 	result = malloc(sizeof(char *) * (count_substring(s, c) + 1));
// 	if (!result)
// 		return (0);
// 	while (*s)
// 	{
// 		if (*s != c)
// 		{
// 			len = 0;
// 			while (*s && *s != c && ++len)
// 				++s;
// 			result[i++] = ft_substr(s - len, 0, len);
// 		}
// 		else
// 			++s;
// 	}
// 	result[i] = 0;
// 	return (result);
// }

// int	main()
// {
// 	char	str[] = "Hello, World ,,,!";
// 	char	c = ' ';
// 	char	**spt = ft_split(str, c);
// 	int	i = 0;
// 	while (spt[i] != 0)
// 	{
// 		ft_putstr_fd(spt[i], 1);
// 		i++;
// 	}
// 	ft_putchar_fd('\n', 1);
//  free(**spt);
// }