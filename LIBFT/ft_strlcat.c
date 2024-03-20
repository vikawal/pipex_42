/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:26:02 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/12 15:38:25 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <bsd/string.h>
// #include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	end;

	i = 0;
	while (dst[i] && i < size)
	{
		i++;
	}
	end = ft_strlcpy(dst + i, src, size - i);
	return (end + i);
}
// int main()
// {
// 	char dst1[] = "";//mine
// 	char dst2[] = "";//original
// 	const char *src = "Hello, my stl_copy";
// 	size_t size = sizeof(dst1);
// 	size_t original = strlcat(dst2, src, size);
// 	size_t result = ft_strlcat(dst1, src, size);
// 	printf("%s\n length: %zu\n", dst1, result);
// 	printf("%s\n length: %zu\n", dst2, original);
// }