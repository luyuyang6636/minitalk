/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:59:44 by luyang            #+#    #+#             */
/*   Updated: 2023/11/28 15:59:46 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned(t_flags flags, unsigned int n)
{
	int	length;

	length = 0;
	flags.plus = 0;
	flags.space = 0;
	if (!(flags.error && n == 0))
	{
		if (flags.left)
			length += ft_print_int_body(flags, (long)n);
		length += ft_padding(flags, n, ft_nbrlen);
		if (!flags.left)
			length += ft_print_int_body(flags, (long)n);
	}
	else
		length += ft_padding(flags, n, ft_nbrlen);
	return (length);
}
