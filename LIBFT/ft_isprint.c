/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:32:39 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/04 19:16:21 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include "stdio.h"
// #include <ctype.h>

int	ft_isprint(int c)
{
	return ((c >= 32 && c <= 126));
}
// int main()
// {
// printf("%d\n", ft_isprint(3));
// printf("%d\n", isprint(3));
// }
