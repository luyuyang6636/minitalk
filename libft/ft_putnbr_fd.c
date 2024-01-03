/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:12:25 by luyang            #+#    #+#             */
/*   Updated: 2023/11/02 15:41:22 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		c = '-';
		ft_putchar_fd(c, fd);
		nb *= -1;
	}
	if (nb / 10)
		ft_putnbr_fd(nb / 10, fd);
	c = '0' + nb % 10;
	ft_putchar_fd(c, fd);
}

/*int	main(void)
{
	ft_putnbr_fd(-1526, 1);
}*/
