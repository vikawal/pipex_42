/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:32:02 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/23 12:08:22 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	size_t	i;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
	}
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
	{
		i--;
	}
	trimmed_str = ft_substr(s1, 0, i + 1);
	return (trimmed_str);
}

// int main ()
// {
// 	char string1[] = "liDo you like C?ke";
// 	char string2[] = "like";
// 	char *trimmed = ft_strtrim(string1, string2);
// 	printf("Trimmed string is: %s", trimmed);
// free(trimmed);
// }