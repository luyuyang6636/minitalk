/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:04:24 by luyang            #+#    #+#             */
/*   Updated: 2023/10/31 17:51:26 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*ret;

	ret = dest;
	if (src < dest)
	{
		src += n;
		dest += n;
		while (n--)
			*(unsigned char *)--dest = *(unsigned char *)--src;
	}
	else
	{
		while (n--)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
	}
	return (ret);
}

/*int	main(void)
{
	char	des[50] = "Lululululululu";
	char	sr[50] = "Dorodorodoro";

	ft_memmove(des, sr, 5);
	printf("%s", des);
	return (0);
}*/
