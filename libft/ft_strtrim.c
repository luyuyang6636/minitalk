/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:55:03 by luyang            #+#    #+#             */
/*   Updated: 2023/11/01 18:29:14 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/
#include "libft.h"

int	ft_check(const char c, char const *set)
{
	int	i;

	i = 0;
	while (c != set[i] && set[i])
		i++;
	if (c == set[i])
		return (1);
	else
		return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	while (s1[start] && ft_check(s1[start], set) == 1)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_check(s1[end - 1], set))
		end--;
	ret = malloc (sizeof(char) * (end - start + 1));
	if (!ret)
		return (0);
	i = 0;
	while (start < end)
		ret[i++] = s1[start++];
	ret[i] = '\0';
	return (ret);
}

/*int	main(void)
{
	const char	test[]="   xxx   xxx";
	printf("%s\n", ft_strtrim(test, " x"));
}*/
