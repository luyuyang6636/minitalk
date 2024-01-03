/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:53:16 by luyang            #+#    #+#             */
/*   Updated: 2023/11/01 11:12:55 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*#include <stdio.h>*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*src && i < size - 1 && size > 0)
	{
		*dst++ = *src++;
		i++;
	}
	if (i < size)
		*dst = '\0';
	while (*src++)
		i++;
	return (i);
}

/*int	main(void)
{
	char	dst[50]="Happy halloween!";
	const char	src[50]="Merry Xmas!";

	ft_strlcpy(dst, src, 5);
	printf("%s", dst);
	printf("\n%zu", ft_strlcpy(dst, src, 5));
}*/
