/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:38:14 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/11 17:21:26 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && *s1 != '\0' && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
//  int main()
// {
// 	char string_1[] = "It is the same string";
// 	char string_2[] = "It is zzzz NOT the same string";
// 	char string_3[] = "It is the same string";
// 	char string_4[] = "It is";
//     unsigned int n = 8;
// 	int result_0 = strncmp(string_1, string_4, 0);// must return 0

// 	int result_1 = ft_strncmp(string_1, string_2, n);// must return -
// 	int result_2 = ft_strncmp(string_1, string_3, n); // should return 0 - SAME
// 	int result_3 = ft_strncmp(string_1, string_4, n);// ++ (short is first)
// 	printf("Compare case on n == 0: %d\n", result_0);
// 	printf("Compare 1 and 2 different strings: %d\n", result_1);
// 	printf("Compare 1 and 3 SAME strings: %d\n", result_2);
// 	printf("Compare 1 and 4 short and long strings: %d\n", result_3);
// }