/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:34:59 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/11 17:25:32 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	char_c;
	int				count;

	char_c = (unsigned char)c;
	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	while (count >= 0)
	{
		if (s[count] == char_c)
		{
			return ((char *)(s + count));
		}
		count--;
	}
	return (0);
}
// int main()
// {
// 	char test_string[] = "Hello, bye, abc";
// 	char *test = test_string;
// 	int c = 'b';
// 	char *result = ft_strrchr(test, c);
// 	if (result)
// 	{
// 		printf("character %c found at position %p\n", c, result);
// 	}
// 	else
// 	{
// 		printf("character %c NOT found\n", c);
// 	}
// 	char *result_1 = strrchr(test, c);
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