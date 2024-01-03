/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:17:02 by luyang            #+#    #+#             */
/*   Updated: 2023/11/01 17:31:43 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*nclude <stdio.h>*/
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total;
	char	*ret;
	size_t	i;

	total = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc (sizeof(char) * (total + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s1)
	{
		ret[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		ret[i] = *s2;
		s2++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

/*int	main(void)
{
	printf("%s", ft_strjoin("pla", ""));
}*/
