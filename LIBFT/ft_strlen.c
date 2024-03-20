/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:32:38 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/04 19:26:52 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include "unistd.h"
// #include <stdio.h>
// #include <string.h>
//hi

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

// int main()
// {
//     const char *str_1 = "Hello, my first library";

//     size_t my_length = ft_strlen(str_1);

//     size_t expected_length = strlen(str_1);

//     printf("I expect '%zu', I get '%zu'", expected_length, my_length);
// }
