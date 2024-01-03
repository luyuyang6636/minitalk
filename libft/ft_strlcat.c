/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:19:25 by luyang            #+#    #+#             */
/*   Updated: 2023/11/01 11:48:53 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*#include <stdio.h>*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;

	i = 0;
	dstlen = 0;
	while (*dst && dstlen < size)
	{
		dstlen++;
		dst++;
	}
	while ((i + 1 < size - dstlen) && *src && (size > dstlen))
	{
		*dst++ = *src++;
		i++;
	}
	if (i < size - dstlen && (size > dstlen))
		*dst = '\0';
	while (*src++)
		i++;
	return (dstlen + i);
}

/*int	main(void)
{
	char	dst[50]="Happy halloween!";
	const char	src[50]="Merry Xmas!";

	ft_strlcat(dst, src, 8);
	printf("%s", dst);
	printf("\n%zu", ft_strlcat(dst, src, 8));
}*/
