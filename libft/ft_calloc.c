/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:25:37 by luyang            #+#    #+#             */
/*   Updated: 2023/11/01 15:53:11 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;
	size_t	total;

	total = nmemb * size;
	if (nmemb)
	{
		if (total / nmemb != size)
			return (0);
	}
	ret = malloc(nmemb * size);
	if (!ret)
		return (0);
	ft_bzero(ret, nmemb * size);
	return (ret);
}

/*int	main(void)
{
	void	*space;

	space = ft_calloc(4, 4);
}*/
