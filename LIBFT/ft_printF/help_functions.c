/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:00:20 by vmyshko           #+#    #+#             */
/*   Updated: 2024/01/12 13:15:37 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft.h"

int	print_putchar(char c)
{
	return (write(1, &c, 1));
}

int	print_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	print_putnbr(int n)
{
	long	num;
	int		length;

	num = n;
	length = 0;
	if (num < 0)
	{
		print_putchar('-');
		num = -num;
		length++;
	}
	if (num / 10)
	{
		length = length + print_putnbr((num / 10));
		length = length + print_putnbr((num % 10));
	}
	else
	{
		print_putchar(('0' + num));
		length++;
	}
	return (length);
}

unsigned int	print_unsigned_putnbr(unsigned int n)
{
	int		length;

	length = 0;
	if (n / 10)
	{
		length = length + print_unsigned_putnbr((n / 10));
		length = length + print_unsigned_putnbr((n % 10));
	}
	else
	{
		print_putchar(('0' + n));
		length++;
	}
	return (length);
}

// int main ()
// {
// 	printf("\n%d\n",print_putchar_fd('A'));
// 	printf("\n%c\n", 'A');
// 	printf("\n%d\n",print_putstr_fd("Hello"));
// 	printf("\n%s\n", "Hello");
// 	printf("\n%d\n",print_putnbr_fd(-123));
// 	printf("\n%d\n", -123);
// 	printf("\n%i\n", -123);	
// 	printf("\n%d\n",print_unsigned_putnbr_fd(-123));
// 	printf("\n%u\n", -123);
// 	return (0);
// }