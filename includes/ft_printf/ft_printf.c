/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:07:23 by jnajul            #+#    #+#             */
/*   Updated: 2024/03/27 16:19:16 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char conversion, va_list ap)
{
	int	count;

	count = 0;
	if (conversion == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (conversion == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (conversion == 'd' || conversion == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (conversion == 'u')
		count += ft_putunbr(va_arg(ap, unsigned int));
	else if (conversion == 'p')
		count += ft_putptr(va_arg(ap, unsigned long));
	else if (conversion == 'x' || conversion == 'X')
		count += ft_puthex(va_arg(ap, unsigned int), conversion);
	else if (conversion == '%')
		count += ft_putchar('%');
	else
		count += write (1, &conversion, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_format(format[i], args);
		}
		else
		{
			write (1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end (args);
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int z;

// 	z = -24152452;
// 	ft_printf("\n%d\n",ft_printf("%d %i %c %p %u %% %x %X", 245241665,-24152452 
// 	, 45, &z, 54564, 45565, 45565));
// 	printf("\n%d\n",printf("%d %i %c %p %u %% %x %X", 
// 	245241665,-24152452,45, &z, 54564, 45565, 45565));
// 	return (0);
// }