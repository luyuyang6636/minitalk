/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:57:31 by luyang            #+#    #+#             */
/*   Updated: 2023/11/01 16:08:25 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	len;
	int		i;

	len = ft_strlen(s);
	ret = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!ret)
		return (0);
	while (*s)
	{
		ret[i] = *s++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

/*int	main(void)
{
	printf("%s", ft_strdup("Hiya!"));
}*/
