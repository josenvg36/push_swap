/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:31:27 by jnajul            #+#    #+#             */
/*   Updated: 2024/03/27 14:45:53 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6), 6);
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = ft_nbrlen(n);
	while (n < 0)
	{
		if (n == -2147483648)
		{
			write (1, "-2147483648", 11);
			return (11);
		}
		else
		{
			ft_putchar('-');
			n = -n;
		}
	}
	if (n / 10 != 0)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar(n % 10 + '0');
	return (i);
}

int	ft_putunbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n >= 10)
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int	ft_puthex(unsigned int n, const char x)
{
	int	i;

	i = 0;
	if (n == 0)
		return (ft_putchar ('0'));
	if (n >= 16)
	{
		ft_puthex (n / 16, x);
		ft_puthex (n % 16, x);
	}
	else
	{
		if (n <= 9)
			ft_putchar (n + '0');
		else if (x == 'x')
			ft_putchar (n - 10 + 'a');
		else if (x == 'X')
			ft_putchar (n - 10 + 'A');
	}
	while (n)
	{
		i++;
		n = n / 16;
	}
	return (i);
}
