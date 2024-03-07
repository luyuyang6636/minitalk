/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:56:20 by luyang            #+#    #+#             */
/*   Updated: 2023/11/20 21:18:00 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_print_int_body(t_flags flags, long n)
{
	int	length;

	length = 0;
	if (n >= 0)
	{
		if (flags.plus)
			length += ft_put_char('+');
		else if (flags.space)
			length += ft_put_char(' ');
	}
	else
	{
		length += ft_put_char('-');
		n *= -1;
	}
	if (ft_nbrlen(n) < flags.precision)
	{
		while (flags.precision-- - ft_nbrlen(n) > 0)
			length += ft_put_char('0');
	}
	ft_putnbr(n);
	length += ft_nbrlen(n);
	return (length);
}

int	ft_print_int(t_flags flags, long n)
{
	int	length;

	length = 0;
	if (!(flags.error && n == 0))
	{
		if (flags.zero && flags.width && n < 0)
		{
			flags.zero = 0;
			flags.precision = flags.width - 1;
		}
		if (flags.left)
			length += ft_print_int_body(flags, n);
		length += ft_padding(flags, n, ft_nbrlen);
		if (!flags.left)
			length += ft_print_int_body(flags, n);
	}
	else
		length += ft_padding(flags, n, ft_nbrlen);
	return (length);
}

void	ft_putnbr(long n)
{
	if (n < 0)
	{
		ft_put_char('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_put_char(n + '0');
}

/*int	ft_print_unsigned(unsigned int n)
{
	if (n > 9)
	{
		ft_print_unsigned(n / 10);
		ft_print_unsigned(n % 10);
	}
	else
		ft_printchar(n + '0');
}*/
