/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:25:43 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/12 11:58:43 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*char_s1;
	unsigned char	*char_s2;
	size_t			i;

	char_s1 = (unsigned char *)s1;
	char_s2 = (unsigned char *)s2;
	i = 0;
	while (n > 0)
	{
		if (*char_s1 != *char_s2)
		{
			return (*char_s1 - *char_s2);
		}
		char_s1++;
		char_s2++;
		n--;
	}
	return (0);
}

// int main(void)
// {
// 	char s[] = {-128, 0, 127, 0};
// 	char sCpy[] = {-128, 0, 127, 0};
// 	char s2[] = {0, 0, 127, 0};
// 	char s3[] = {0, 0, 42, 0};

// 	int result_0 = ft_memcmp(s, sCpy, 0);// must return 0 
// 	int result_01 = ft_memcmp(s, sCpy, 3);// must return 0 the same

// 	int result_1 = ft_memcmp(s, s2, 2);// must return +
// 	int result_2 = ft_memcmp(s2, s, 2); // must return -
// 	int result_3 = ft_memcmp(s2, s3, 4);// ++ (short is first)
// 	printf("Compare case on n == 0: %d\n", result_0);
// 	printf("Compare SAME: %d\n", result_01);
// 	printf("Compare different (+): %d\n", result_1);
// 	printf("Compare previous reverse (-): %d\n", result_2);
// 	printf("Compare 127-42: %d\n", result_3);
// }