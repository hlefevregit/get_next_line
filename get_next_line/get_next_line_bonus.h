/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlefevre <hlefevre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:00:18 by hlefevre          #+#    #+#             */
/*   Updated: 2021/12/01 17:09:28 by hlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*gnl_newfile(int fd, char *save);
char	*gnl_getline(char *str);
char	*get_backup(char *save);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

size_t	ft_strlen(const char *str);

#endif