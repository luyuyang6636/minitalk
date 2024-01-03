/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:47:44 by luyang            #+#    #+#             */
/*   Updated: 2023/11/01 20:03:23 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_return(int count, long original, int divide, int nb)
{
	char	*ret;

	ret = malloc (sizeof(char) * (count + 1));
	if (!ret)
		return (NULL);
	count = 0;
	if (nb < 0)
		ret[count++] = '-';
	while (divide >= 1)
	{
		ret[count++] = original / divide + '0';
		original = original % divide;
		divide /= 10;
	}
	ret[count] = '\0';
	return (ret);
}

char	*ft_itoa(int nb)
{
	int		divide;
	int		count;
	long	original;

	count = 1;
	original = nb;
	divide = 1;
	if (original < 0)
	{
		original *= -1;
		count++;
	}
	while (original / divide >= 10)
	{
		divide *= 10;
		count++;
	}
	return (ft_return(count, original, divide, nb));
}

/*int	main(void)
{
	printf ("%s", ft_itoa(2147));
}*/	
