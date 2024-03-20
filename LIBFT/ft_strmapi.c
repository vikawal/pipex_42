/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:49:13 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/23 16:53:04 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = ft_strdup(s);
	if (!s || !f || !str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}

//  char	new_test2 (unsigned int i, char c)
// {
// 		if (c >= 'A' && c <= 'Z')
// 			c = c + 32;
// 	return (c);
// }
// int main ()
// {
// 	char a[] = "HELLO, I'll be in LOWER case soon!";
// 	char *result = ft_strmapi(a, new_test2);
// 	printf("New string: %s\n", result);
// 	free(result);
// 	return (0);
// }