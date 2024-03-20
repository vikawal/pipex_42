/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:06:01 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/23 12:22:56 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (*little == 0)
		return ((char *)big);
	while (*big && little_len <= len)
	{
		if (*big == *little && ft_strncmp(big, little, little_len) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (0);
}

// int main (void)
// {
// 	char string_1[] = "It is the same string";
// 	char string_2[] = "same";	
// 	char *result_0 = ft_strnstr(string_1, string_2, 5);
// 	char *result_1 = ft_strnstr(string_1, string_2, 20);
// 	char *result_00 = strnstr(string_1, string_2, 5);
// 	char *result_11 = strnstr(string_1, string_2, 20);
// 	printf("NOT found %p\n", ( void*)result_0);
// 	printf("FOUND %p\n", ( void*)result_1);
// 	printf("NOT found %p\n", ( void*)result_00);
// 	printf("FOUND %p\n", ( void*)result_11);
// }