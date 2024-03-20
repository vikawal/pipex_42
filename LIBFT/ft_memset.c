/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:09:13 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/04 19:22:53 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include "stdio.h"
// #include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

// int main()
// {
//     char string_1[] = "Hello, memset!";
//     ft_memset(string_1, 'A', 5);
//     printf("%s\n", string_1);
//     memset(string_1, 'B', 5);
//     printf("%s\n", string_1);
// }
