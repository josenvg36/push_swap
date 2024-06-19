/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:03:11 by jnajul            #+#    #+#             */
/*   Updated: 2024/04/05 15:01:25 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		i ++;
	}
	if (i == 0)
		return (1);
	return (i);
}

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putptr(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (write(1, "(nil)", 5), 5);
	write (1, "0x", 2);
	i += ft_puthexptr(n);
	return (i + 2);
}

int	ft_puthexptr(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (ft_putchar ('0'));
	if (n >= 16)
	{
		ft_puthexptr (n / 16);
		ft_puthexptr (n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar (n + '0');
		else
			ft_putchar (n - 10 + 'a');
	}
	while (n)
	{
		i++;
		n = n / 16;
	}
	return (i);
}
