/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:21:49 by vmyshko           #+#    #+#             */
/*   Updated: 2024/01/12 13:15:11 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft.h"
#include <stdarg.h>

int	ft_print_arg(va_list args, char format)
{
	if (format == 'c')
		return (print_putchar(va_arg(args, int)));
	else if (format == 's')
		return (print_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (print_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (print_unsigned_putnbr(va_arg(args, unsigned int)));
	else if (format == 'X')
		return (print_hex_upper(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (print_hex_lower(va_arg(args, unsigned int)));
	else if (format == 'p')
		return (print_pointer(va_arg(args, unsigned long)));
	else if (format == '%')
		return (print_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = len + ft_print_arg(args, format[i + 1]);
			i++;
		}
		else
			len = len + print_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

// int	main()
// {
// 	printf("Char: %c, string: %s, just %%\n", 'A', "hello");
// 	ft_printf("Char: %c, string: %s, just %%\n", 'A', "hello");
// 	printf("decimal: %d, integer: %i\n", 12, 173);
// 	ft_printf("decimal: %d, integer: %i\n", 12, 173);
// 	printf("Unsigned int: %u\n", 429496729);
// 	ft_printf("Unsigned int: %u\n", 429496729);
// 	printf("hexadecimal (base 16) low: %x, and up: %X\n", 125667, 1738432);
// 	ft_printf("hexadecimal (base 16) low: %x, and up: %X\n", 125667, 1738432);
// 	printf("\n%p\n", (void *)123);
//     ft_printf("\n%p\n", (void *)123);
//  return (0);
// }