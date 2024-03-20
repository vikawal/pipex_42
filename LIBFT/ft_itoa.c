/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:01:27 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/25 18:09:54 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned int	check_len_size(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

// static char *get_char(char *s, unsigned int num, long int len)
// {
// 	s[len] = '\0';
// 	if (num < 0)
// 		num = -num;
// 	while (len > 0)
// 	{
// 		s[len] = '0' + (num % 10);
// 		num = num / 10;
// 		len--;
// 	}
// 	return (s);
// }
char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	len;
	long			num;

	num = (long)n;
	len = check_len_size(n);
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	if (num < 0)
		num = -num;
	s[len] = '\0';
	while (len--)
	{
		s[len] = '0' + (num % 10);
		num = num / 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}

// int main()
// {
// 	// check_len_size (-124);
// 	char *str1 = ft_itoa(10);
// 	char *str2 = ft_itoa(-2147483648);
// 	char *str3 = ft_itoa(2147483647);
// 	char *str4 = ft_itoa(0);

// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	printf("%s\n", str3);
// 	printf("%s\n", str4);

// 	free(str1);
// 	free(str2);
// 	free(str3);
// 	free(str4);

// 	return (0);

// }