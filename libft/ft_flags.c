/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:06:02 by luyang            #+#    #+#             */
/*   Updated: 2023/11/24 13:06:03 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flags	ft_reset_flags(void)
{
	t_flags	flags;

	flags.left = 0;
	flags.zero = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.width = 0;
	flags.type = 0;
	flags.dot = 0;
	flags.precision = 0;
	flags.hash = 0;
	flags.error = 0;
	return (flags);
}

t_flags	ft_set_flags_wp(t_flags flags, const char *format)
{
	if (*format == '.' || (ft_isdigit(*format) == 1))
	{
		if (*format >= '1' && *format <= '9')
			flags.width = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
			format++;
		if (*format++ == '.')
		{
			flags.dot = 1;
			if (ft_isdigit(*format) == 1)
				flags.precision = ft_atoi(format);
		}
	}
	return (flags);
}

t_flags	ft_set_format(t_flags flags, const char *format)
{
	while (ft_strchr_printf("+-0# ", format))
		flags = ft_set_flags(flags, format++);
	if (*format == '.' || (*format >= '1' && *format <= '9'))
		flags = ft_set_flags(flags, format);
	while (*format == '.' || (*format >= '0' && *format <= '9'))
		format++;
	if (ft_strchr_printf("cspdiuxX%", format))
	{
		flags.type = *format;
		format++;
	}
	flags = ft_flags_check_error(flags);
	return (flags);
}

t_flags	ft_set_flags(t_flags flags, const char *format)
{
	if (*format == '-')
		flags.left = 1;
	else if (*format == '0')
		flags.zero = 1;
	else if (*format == ' ')
		flags.space = 1;
	else if (*format == '+')
		flags.plus = 1;
	else if (*format == '#')
		flags.hash = 1;
	if (flags.left)
		flags.zero = 0;
	if (flags.plus)
		flags.space = 0;
	flags = ft_set_flags_wp(flags, format);
	return (flags);
}

t_flags	ft_flags_check_error(t_flags flags)
{
	if (flags.dot == 1 && flags.precision == 0
		&& ft_strchr_printf("iduxX", &flags.type))
		flags.error = 1;
	if (flags.zero && flags.dot)
		flags.zero = 0;
	return (flags);
}
