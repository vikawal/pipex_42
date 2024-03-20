/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:53:15 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/23 15:41:39 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// void new_test (unsigned int i, char *str)
// {
// 	i = 0;
// 	str[i] = ft_toupper((unsigned char)str[i]);
// 	// if (str[i] >= 'a' && str[i] <= 'z')
// 	// {
// 	// 	str[i] = str[i] - 32;
// 	// }
// }
// int main ()
// {
// 	char a[] = "Hello, I'll be in upper case soon!";
// 	ft_striteri(a, new_test);
// 	printf("New string: %s\n", a);
// 	return (0);
// }