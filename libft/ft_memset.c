/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:47:07 by luyang            #+#    #+#             */
/*   Updated: 2023/10/31 16:16:28 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*#include <stdio.h>*/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	void	*ret;

	i = 0;
	ret = s;
	while (i++ < n)
		*(unsigned char *) s++ = (unsigned char) c;
	return (ret);
}

/*int	main(void)
{
	char	str[50] = "Hi this is Lulu";

	ft_memset(str, '0', 5);
	printf("%s", str);
	return (0);
}*/
