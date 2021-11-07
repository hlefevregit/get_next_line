/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:58:11 by marvin            #+#    #+#             */
/*   Updated: 2021/10/31 16:58:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stats.h>

char    *ft_strcat(char *dest, const char *src)
char    *ft_strchr(const char *s, int c);
char    *ft_strdup(const char *s);
char    *get_next_line(int fd);

size_t  ft_strlcpy(char *dest, const char *src, size_t size);
size_t  ft_strlen(const char *str)

#endif