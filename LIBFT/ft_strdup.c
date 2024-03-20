/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:31:39 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/13 12:32:01 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	length;

	length = ft_strlen(s) + 1;
	dest = malloc(length);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s, length);
	return (dest);
}

// int main ()
// {
// 	char src[] = "Hello, strdup!";
// 	char *result_1 = ft_strdup(src);
// 	char *result_2 = strdup(src);
// 	printf("Start string: %s\n", src);
// 	printf("My strdup: %s\n", result_1);
// 	printf("Original strdup: %s\n", result_2);
// 	free(result_1);
// 	free(result_2);
// 	return (0);
// }