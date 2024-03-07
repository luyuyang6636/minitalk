/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:16:32 by luyang            #+#    #+#             */
/*   Updated: 2023/11/09 13:16:34 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_full(char *remain, int fd)
{
	char	*buffer;
	int		bytes;

	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	bytes = 1;
	if (!buffer)
		return (NULL);
	while (!ft_strchr(remain, '\n') && bytes != 0)
	{
		bytes = read (fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		remain = ft_strjoin(remain, buffer);
	}
	free (buffer);
	return (remain);
}

char	*ft_get_line(char *remain)
{
	char	*line;
	int		i;

	i = 0;
	if (!remain[i])
		return (NULL);
	while (remain[i] != '\n' && remain[i] != '\0')
		i++;
	line = malloc (sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (remain[i] && remain[i] != '\n')
	{
		line[i] = remain[i];
		i++;
	}
	if (remain[i] == '\n')
	{
		line[i] = remain[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_left(char *remain)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	while (remain[i] != '\n' && remain[i] != '\0')
		i++;
	if (!remain[i])
	{
		free(remain);
		return (NULL);
	}
	ret = malloc (sizeof(char) * (ft_strlen(remain) - i + 1));
	if (!ret)
		return (NULL);
	i++;
	j = 0;
	while (remain[i])
		ret[j++] = remain[i++];
	ret[j] = '\0';
	free (remain);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*remain[10000];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remain[fd] = ft_full(remain[fd], fd);
	if (!remain[fd])
		return (NULL);
	line = ft_get_line(remain[fd]);
	remain[fd] = ft_left(remain[fd]);
	return (line);
}
