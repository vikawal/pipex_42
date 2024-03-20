/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:32:33 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/11 18:23:17 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	char_c;
	unsigned char	*char_s;
	size_t			i;

	char_c = (unsigned char)c;
	char_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (char_s[i] == char_c)
			return (char_s + i);
		i++;
	}
	return (0);
}
// int main()
// {
// 	char test_string[] = "Hello, bye, abc";
// 	char *test = test_string;
// 	int c = 'b';
// 	size_t n = 10;
// 	char *result = memchr(test, c, n);
// 	if (result)
// 	{
// 		printf("character %c found at position %p\n", c, result);
// 	}
// 	else
// 	{
// 		printf("character %c NOT found\n", c);
// 	}
// 	char *result_1 = memchr(test, c, n);
// 	if (result)
// 	{
// 		printf("character %c found at position %p\n", c, result_1);
// 	}
// 	else
// 	{
// 		printf("character %c NOT found\n", c);
// 	}
// 	return(0);
// }
// int  main ()
// {
// 	int intArray[] = {1, 2, 3, 4, 5};
// 	void *result = memchr(intArray, 2, 5);//sizeof(intArray)//????
// 	if (result != NULL) {
// // Calculate the position in the array
//  size_t position = ((char *)result - (char *)intArray) / sizeof(int);
// printf("Found %d at position %zu\n", 2, position);//Found 2 at position 1
// 	} 
// 	else 
// 	 printf("%d not found in the array.\n", 2);
// }
