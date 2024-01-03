/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:12:22 by luyang            #+#    #+#             */
/*   Updated: 2023/11/01 17:09:33 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*#include <stdio.h>*/

size_t	check(char const *s, unsigned int start, size_t len)
{
	size_t	slen;

	slen = ft_strlen(s);
	if (slen > start)
	{
		if (start + len > slen)
			len = slen - start;
	}
	else
		len = 0;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ret;
	int			i;
	char const	*point;

	i = 0;
	len = check(s, start, len);
	ret = malloc (sizeof (char) * (len + 1));
	if (!ret)
		return (NULL);
	if (ft_strlen(s) > start)
	{
		point = s + start;
		while (len--)
		{
			ret[i] = *point++;
			i++;
		}
	}
	ret[i] = '\0';
	return (ret);
}

/*int	main(void)
{
	printf("%s", ft_substr("Please copy this: Hi it is cold today", 10, 30));
}*/
