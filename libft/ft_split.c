/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:13:06 by luyang            #+#    #+#             */
/*   Updated: 2023/11/01 19:42:40 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/
#include "libft.h"

int	ft_countword(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || !s[i + 1]) && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**ret;
	size_t	len;

	while (*s == c && *s)
		s++;
	ret = malloc (sizeof(char *) * (ft_countword(s, c) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ret[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	ret[i] = 0;
	return (ret);
}

/*int	main(void)
{
	char s[] = "     ";
	char c = ' ';
	char **array;
	int	i;

	i = 0;
	array = ft_split(s, c);
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
	return(0);
}*/
