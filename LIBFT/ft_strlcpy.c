/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:29:47 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/12 15:38:51 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
#include <bsd/string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size -1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
// int main()
// {
// 	char src[] = "Do you like C? Don't lie! I know you do";
// 	char dest[5]; //buffer big enough to hold our full string if necessary
// 	size_t result_size;
// 	size_t result_size_1;	
// 	result_size = ft_strlcpy(dest, src, sizeof(dest));
// 	printf("Copied %zu characters: %s\n", result_size, dest);
// 	result_size_1 = strlcpy(dest, src, sizeof(dest));
// 	printf("Copied %zu characters: %s\n", result_size_1, dest);
// }