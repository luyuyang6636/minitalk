/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:32:56 by luyang            #+#    #+#             */
/*   Updated: 2023/10/31 17:00:22 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*ret;

	if (!src && !dest)
		return (0);
	ret = dest;
	while (n--)
		*(unsigned char *) dest++ = *(unsigned char *) src++;
	return (ret);
}

/*int	main(void)
{
	char	des[50] = "Lululululululu";
	char	sr[50] = "Dorodorodoro";

	ft_memcpy(des, sr, 5);
	printf("%s", des);
	return (0);
}*/
