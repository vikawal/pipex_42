/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:58:58 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/24 16:26:01 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == 0 && src == 0)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
// int main ()
// {
// 	char src[] = "Hello, memcopy!";
// 	char dest[20];

// 	int a[20] = {1, 2, 3};
// 	int b[20] = {4, 5, 6};
// 	ft_memcpy(b, a, sizeof(b));

// 	int i = 0;
// 	while (i != 20) {
// 		printf("%d, ", b[i]);
// 	}

// 	// ft_memcpy(dest, src, strlen(src) +1);
// 	// memcpy(dest, src, 5);
// 	ft_memcpy(dest, src, 5);
// 	printf("%s\n", dest);

// 	return (0);
// }