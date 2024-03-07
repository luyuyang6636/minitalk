/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:25:58 by luyang            #+#    #+#             */
/*   Updated: 2023/11/20 20:51:47 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptrlen(unsigned long int ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (0);
	while (ptr > 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

void	ft_put_ptr(unsigned long int ptr)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16);
		ft_put_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_put_char('0' + ptr);
		else
			ft_put_char(ptr - 10 + 'a');
	}
}

void	ft_put_ptr_left(t_flags flags, unsigned long int ptr, int length)
{
	int	diff;

	diff = flags.width - length;
	if (!ptr)
	{
		flags.width -= 5;
		ft_putstr("(nil)");
		while (flags.width-- > 0)
		{
			ft_put_char(' ');
		}
	}
	else
	{
		ft_putstr("0x");
		ft_put_ptr(ptr);
		while (diff-- > 0)
			ft_put_char(' ');
	}
}

void	ft_put_ptr_no_left(t_flags flags, unsigned long int ptr, int length)
{
	int	diff;

	diff = flags.width - length;
	if (!ptr)
	{
		flags.width -= 5;
		while (flags.width-- > 0)
		{
			ft_put_char(' ');
		}
		ft_putstr("(nil)");
	}
	else
	{
		while (diff--)
			ft_put_char(' ');
		ft_putstr("0x");
		ft_put_ptr(ptr);
	}
}

int	ft_print_ptr(t_flags flags, unsigned long int ptr)
{
	int	length;

	length = ft_ptrlen(ptr);
	if (length != 0)
		length += 2;
	if (flags.width > length)
	{
		if (flags.left)
			ft_put_ptr_left(flags, ptr, length);
		else
			ft_put_ptr_no_left(flags, ptr, length);
		if (!ptr && flags.width < 5)
			return (5);
		return (flags.width);
	}
	else
	{
		if (!ptr)
			return (ft_putstr("(nil)"));
		ft_putstr("0x");
		ft_put_ptr(ptr);
		return (length);
	}
}
