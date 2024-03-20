/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:30:43 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/09 14:55:06 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = dest;
	s = src;
	if (d == s)
	{
		return (dest);
	}
	if (s < d)
	{
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	else
	{
		ft_memcpy (d, s, n);
	}
	return (dest);
}
// int main()
// {
	// char src[100] = "HelloMem_move";
// 	char src_1[100] = "HelloMem_move";
// 	char empty[] = "Edge_case";
// 	char empty_1[] = "Edge_case";
// ft_memmove(src+7, src, strlen(src)+1);
// 	memmove(src_1+7, src_1, strlen(src_1)+1);
// 	printf("%s\n%s\n", src, src_1);
// 	ft_memmove(empty, src, 0);
// 	memmove(empty_1, empty_1, 0);
// 	printf("%s\n%s\n", empty, empty_1);
// 	ft_memmove(empty, src, 5);
// 	memmove(empty_1, empty, 5);
// 	printf("%s\n%s", empty, empty_1);
// 	return (0);

// }
