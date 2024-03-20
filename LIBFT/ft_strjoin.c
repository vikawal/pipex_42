/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:57:43 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/29 13:38:08 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len3;

	len3 = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(char) * (len3 + 1));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, len3 + 1);
	ft_strlcat(s3, s2, len3 + 1);
	return (s3);
}

// int main()
// {
// 	char string1[] = "Do you";
// 	char string2[] = " like C?";
// 	char *joined = ft_strjoin(string1, string2);
// 	printf("Joined string is: %s", joined);
//  free(joined);
// }