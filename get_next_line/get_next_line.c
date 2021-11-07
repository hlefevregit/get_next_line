/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:26:23 by marvin            #+#    #+#             */
/*   Updated: 2021/11/06 12:26:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_getline(char *str)
{
	int     i;
	int		j;
	char    *line;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	j = ft_strlen(ft_strchr(str, '\n')) - 1;
	line = (char *)malloc(i - j + 1);
	ft_strlcpy(line, backup, i - j + 1);
	return (line);
}

static char	*gnl_reset_save(char *save, char *line)
{
	char	*n_save;
	int		i;
	int		j;

	if (save == NULL || line == NULL)
		return (NULL);
	i = ft_strlen(save);
	j = ft_strlen(line);
	if (j <= 0)
	{
		free(save);
		return (NULL);
	}
	n_save = (char *)malloc(i + j + 1);
	ft_strlcpy(n_save, save + j, i - j + 1);
	free(save);
	return (n_save);
}

static char	*gnl_extend_backup(char *save, char *byte)
{
	char	*n_save;
	int		i;
	int		j;

	if (save == NULL || byte == NULL)
		return (NULL);
	i = ft_strlen(save);
	j = ft_strlen(byte);
	n_save = (char *)malloc(i + j + 1);
	ft_strlcpy(n_save, save, i + 1);
	ft_strcat(n_save, byte);
	free(save);
	return (n_save);
}

static char	*gnl_get__until_newline(int fd, char *save)
{
	char	*byte;
	int		reader;

	byte = (char *)malloc(BUFFER_SIZE + 1);
	if (!byte)
	{
		free(byte);
		free(save);
		return (NULL);
	}
	reader = 1;
	while (!strchr(save, '\n') && reader != 0)
	{
		reader = read(fd, byte, BUFFER_SIZE);
		if (reader == -1)
		{
			free(save);
			free(byte);
			return (NULL);
		}
		byte[reader] = 0;
		save = gnl_extend_save(save, byte);
	}
	free(byte);
	return (save);
}

char    *get_next_line(int fd)
{
	char    *save;
	char    *line;
	int     i;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
		save = ft_strdup("");
	save = gnl_get_until_newline(fd, save);
	if (save == NULL)
		return (NULL);
	line = gnl_get_line(save)
	save = gnl_reset_save(save, line);
	if (line[0] == '\0')
	{
		free(backup);
		free(line);
		return (NULL);
	}
	return (line);
}