/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:43:15 by luyang            #+#    #+#             */
/*   Updated: 2023/11/01 12:46:38 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = (char *)s;
	while (*s)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			ret = (char *)s;
		s++;
	}
	if (*(unsigned char *)ret == (unsigned char)c)
		return (ret);
	if (c == 0)
		return ((char *)s);
	else
		return (NULL);
}

/*int	main (void)
{
	ft_strchr("Happy November", 'p');
}*/
