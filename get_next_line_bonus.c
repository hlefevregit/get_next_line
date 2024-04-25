/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:10:40 by hulefevr          #+#    #+#             */
/*   Updated: 2024/04/24 14:27:37 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_backup(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	line = (char *)malloc(ft_strlen(str) - i + 1);
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		line[j++] = str[i++];
	line[j] = '\0';
	free(str);
	return (line);
}

char	*gnl_getline(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*gnl_newfile(int fd, char *save)
{
	char	*buffer;
	int		reader;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	reader = 1;
	while (!ft_strchr(save, '\n') && reader != 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader <= -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[reader] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[32767];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = gnl_newfile(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = gnl_getline(save[fd]);
	save[fd] = get_backup(save[fd]);
	return (line);
}
