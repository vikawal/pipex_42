/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:38:03 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/25 12:36:21 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start < ft_strlen(s) && ft_strlen(s + start) < len)
		len = ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
	{
		return (NULL);
	}
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substr;
// 	size_t	size_left;

// 	size_left = ft_strlen(s + start);
// 	if (!s)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 		return (ft_strdup(""));
// 	if (size_left < len)
// 		len = size_left;
// 	substr = malloc(sizeof(char) * (len + 1));
// 	if (!substr)
// 		return (NULL);
// 	ft_strlcpy(substr, s + start, len + 1);
// 	return (substr);
// }
// int main ()
// {
// 	char src[] = "Do you like C? Don't lie! I know you do";
// 	char *result;
// 	result = ft_substr(src, 7, 13);
// 	printf("made substr from %s to: %s\n", src, result);
// free(result);
// }