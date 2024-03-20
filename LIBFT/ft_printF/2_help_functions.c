/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_help_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:34:21 by vmyshko           #+#    #+#             */
/*   Updated: 2024/01/12 13:15:19 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft.h"

unsigned int	print_hex_upper(unsigned int n)
{
	int		length;
	char	*numbers;

	numbers = "0123456789ABCDEF";
	length = 0;
	if (n / 16)
	{
		length = length + print_hex_upper((n / 16));
	}
	write(1, &numbers[n % 16], 1);
	length++;
	return (length);
}

unsigned int	print_hex_lower(unsigned int n)
{
	int		length;
	char	*numbers;

	numbers = "0123456789abcdef";
	length = 0;
	if (n / 16)
	{
		length = length + print_hex_lower((n / 16));
	}
	write(1, &numbers[n % 16], 1);
	length++;
	return (length);
}

int	write_nil(void)
{
	write (1, "(nil)", 5);
	return (5);
}

unsigned long	print_pointer(unsigned long number)
{
	int		length;
	char	*base;
	char	hex_string[17];
	int		index;

	base = "0123456789abcdef";
	length = 0;
	index = 0;
	if (number == 0)
		return (write_nil());
	write(1, "0x", 2);
	while (number != 0)
	{
		hex_string[index++] = base[number % 16];
		number = number / 16;
	}
	index--;
	while (index >= 0)
	{
		write(1, &hex_string[index--], 1);
		length++;
	}
	return (length + 2);
}
// WORKS, BUT TOO LONG 
// unsigned long	print_pointer(unsigned long number)
// {
// 	int		length;
// 	char	*base;
// 	char	hex_string[17];
// 	int		index;
// 	base = "0123456789abcdef";
// 	length = 0;
// 	index = 0;
// 	if (number == 0)
// 	{
// 		write (1, "(nil)", 5);
// 		return (5);
// 	}
// 	write(1, "0x", 2);
// 	while (number != 0)
// 	{
// 		hex_string[index] = base[number % 16];
// 		index++;
// 		number = number / 16;
// 	}
// 	index--;
// 	while (index >= 0)
// 	{
// 		write(1, &hex_string[index], 1);
// 		length++;
// 		index--;
// 	}
// 	return (length + 2);
// }
// int main ()
// {
// 	// printf("\n%d\n", print_hex_upper(123));
// 	// printf("\n%X\n", 123);
// 	// printf("\n%d\n", print_hex_lower(123));
// 	// printf("\n%x\n", 123);
// 	printf("\n%lu\n", print_pointer(123));
// 	printf("\n%p\n", (void *)123);
// 	return (0);
// }
