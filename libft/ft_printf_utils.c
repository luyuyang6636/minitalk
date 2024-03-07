/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:15:07 by luyang            #+#    #+#             */
/*   Updated: 2023/12/04 16:15:11 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_padding(t_flags flags, long n, int (*f)())
{
	int	count;
	int	diff;

	count = ft_padding_count(flags, n, f);
	diff = flags.width - count;
	while (diff-- > 0)
	{
		if (flags.zero && !flags.left && !flags.dot)
			ft_put_char('0');
		else
			ft_put_char(' ');
	}
	if (flags.width - count > 0)
		return (flags.width - count);
	else
		return (0);
}

int	ft_padding_count(t_flags flags, long n, int (*f)())
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count = 1;
		n *= -1;
	}
	if (flags.precision > f(n))
		count += flags.precision;
	else
		count += f(n);
	if (flags.error && n == 0)
		count = 0;
	if ((flags.plus || flags.space) && n >= 0)
		count++;
	return (count);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_put_char(str[i]);
		i++;
	}
	return (ft_strlen(str));
}

char	*ft_strchr_printf(const char *s, const char *str)
{
	while (*s)
	{
		if (*(unsigned char *)s == (unsigned char)*str)
			return ((char *)s);
		s++;
	}
	if (*str == 0)
		return ((char *)s);
	return (NULL);
}
