/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:01:34 by jnajul            #+#    #+#             */
/*   Updated: 2024/03/27 14:46:55 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_format(char conversion, va_list ap);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_nbrlen(int n);
int	ft_putunbr(unsigned int n);
int	ft_puthex(unsigned int n, const char x);
int	ft_putptr(unsigned long n);
int	ft_puthexptr(unsigned long n);

#endif