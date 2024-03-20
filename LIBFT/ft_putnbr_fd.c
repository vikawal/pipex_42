/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:14:56 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/23 14:45:03 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num / 10)
	{
		ft_putnbr_fd((num / 10), fd);
		ft_putnbr_fd((num % 10), fd);
	}
	else
	{
		ft_putchar_fd(('0' + num), fd);
	}
}

// void	ft_putnbr_fd(int n, int fd)
// {
// 	int	sign;

// 	sign = 1;
// 	if (n < 0)
// 	{
// 		ft_putchar_fd('-', fd);
// 		sign = -1;
// 	}
// 	if (n / 10)
// 	{
// 		ft_putnbr_fd((n / 10) * sign, fd);
// 		ft_putnbr_fd((n % 10) * sign, fd);
// 	}
// 	else
// 	{
// 		ft_putchar_fd(('0' + n) * sign, fd);
// 	}
// }