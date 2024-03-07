/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:23:42 by luyang            #+#    #+#             */
/*   Updated: 2023/11/21 14:23:44 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_char(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_printchar(t_flags flags, int c)
{
	int	len;

	len = flags.width;
	if (len)
	{
		if (flags.left)
		{
			ft_put_char(c);
			while (--len)
				ft_put_char(' ');
		}
		else
		{
			while (--len)
				ft_put_char(' ');
			ft_put_char(c);
		}
		return (flags.width);
	}
	return (ft_put_char(c));
}
