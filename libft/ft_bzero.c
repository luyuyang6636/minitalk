/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:23:30 by luyang            #+#    #+#             */
/*   Updated: 2023/10/31 16:29:27 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*#include <stdio.h>*/
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		*(char *)s++ = '\0';
}

/*int	main(void)
{
	char	str[50] = "Hi this is Lulu";

	ft_bzero(str+3, 5);
	printf("%s", str);
	return (0);
}*/
