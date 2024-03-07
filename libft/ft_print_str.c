/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:57:58 by luyang            #+#    #+#             */
/*   Updated: 2023/11/24 18:58:04 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_printstr_left(t_flags flags, char *str)
{
	int	lenstr;
	int	length;

	length = flags.width;
	lenstr = ft_strlen(str);
	if (flags.precision < lenstr && flags.dot == 1)
	{
		while (flags.width-- > 0)
		{
			while (flags.precision-- > 0 && flags.width-- > 0)
				ft_put_char((int) *str++);
			ft_put_char(' ');
		}
	}
	else
	{
		while (flags.width-- > 0)
		{
			while (*str && flags.width-- > 0)
				ft_put_char((int) *str++);
			ft_put_char(' ');
		}
	}
	return (length);
}

int	ft_printstr_no_left(t_flags flags, char *str)
{
	int	length;
	int	diff;

	length = flags.width;
	if (flags.precision < (int)ft_strlen(str) && flags.dot == 1)
	{
		diff = flags.width - flags.precision;
		while (flags.width -- > 0)
		{
			if (diff-- > 0)
				ft_put_char(' ');
			else
				ft_put_char((int) *str++);
		}
		return (length);
	}
	diff = flags.width - ft_strlen(str);
	while (flags.width-- > 0)
	{
		while (diff-- > 0 && flags.width-- > 0)
			ft_put_char(' ');
		ft_put_char((int) *str++);
	}
	return (length);
}

int	ft_printstr_null_pointer(t_flags flags)
{
	int	length;

	length = 0;
	if ((flags.width == 0 && flags.precision == 0))
		length += ft_putstr("(null)");
	else if (flags.width >= 6 && (flags.precision >= 6 || flags.dot == 0))
	{
		while (flags.width-- - 6 > 0)
			length += ft_put_char(' ');
		length += ft_putstr("(null)");
	}
	else if (flags.precision >= 6 || flags.dot == 0)
		length += ft_putstr("(null)");
	else if (flags.precision < 6)
	{
		while (flags.width-- > 0)
			length += ft_put_char(' ');
	}
	return (length);
}

int	ft_printstr_null(t_flags flags, char *str)
{
	int	length;

	length = 0;
	if (!str)
		length += ft_printstr_null_pointer(flags);
	else
	{
		while (flags.width-- > 0)
			length += ft_put_char(' ');
	}
	return (length);
}

int	ft_printstr(t_flags flags, char *str)
{
	int	length;

	length = 0;
	if (!str || !*str)
		return (ft_printstr_null(flags, str));
	else if (flags.width > (int)ft_strlen(str)
		|| ((flags.width > flags.precision) && flags.dot))
	{
		if (flags.left == 1)
			length = ft_printstr_left(flags, str);
		else
			length = ft_printstr_no_left(flags, str);
	}
	else
	{
		if (flags.precision < (int)ft_strlen(str) && flags.dot != 0)
		{
			while (flags.precision-- > 0)
				length += ft_put_char(*str++);
		}
		else
			length += ft_putstr(str);
	}
	return (length);
}
