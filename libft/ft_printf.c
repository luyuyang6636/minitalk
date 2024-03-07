/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:07:23 by luyang            #+#    #+#             */
/*   Updated: 2023/11/20 18:25:03 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_formats(va_list args, const char *format)
{
	t_flags	flags;
	int		length;

	length = 0;
	while (*format)
	{
		flags = ft_reset_flags();
		if (*format == '%' && *++format)
		{
			flags = ft_set_format(flags, format);
			while (ft_strchr_printf("+-0#. ", format)
				||ft_isdigit(*format))
				format++;
			if (ft_strchr_printf("cspdiuxX%", format))
				format++;
			length += ft_print_all(flags, args);
		}
		else
		{
			length += ft_put_char(*format++);
		}
	}
	return (length);
}

int	ft_print_all(t_flags flags, va_list args)
{
	if (flags.type == 'c')
		return (ft_printchar(flags, va_arg(args, int)));
	if (flags.type == 's')
		return (ft_printstr(flags, va_arg(args, char *)));
	if (flags.type == 'p')
		return (ft_print_ptr(flags, (unsigned long int)va_arg(args, void *)));
	if (flags.type == 'i' || flags.type == 'd')
	{
		return (ft_print_int(flags, (long)va_arg(args, int)));
	}
	if (flags.type == 'u')
	{
		return (ft_print_unsigned(flags, va_arg(args, unsigned int)));
	}
	if (flags.type == 'x' || flags.type == 'X')
		return (ft_print_hex(flags, va_arg(args, unsigned int),
				(const char)flags.type));
	if (flags.type == '%')
		return (ft_put_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;

	if (!format || !*format)
		return (0);
	length = 0;
	va_start(args, format);
	length = ft_formats(args, format);
	va_end(args);
	return (length);
}

/*int	main(void)
{
	int i;
	int i2;

	i = printf(" NULL %s NULL ", (char *)NULL);
	i2 = ft_printf(" NULL %s NULL ", (char *)NULL);
	printf("%d\n", i);
	printf("%d\n", i2);
}*/
