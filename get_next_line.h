/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:20:04 by yerbs             #+#    #+#             */
/*   Updated: 2023/11/10 11:58:16 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buff);

size_t	ft_strlen(const char *str);

void	ft_update(char **line, char *buffer);
void	ft_read(int fd, char **line, char *buffer, int *br);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

int		ft_check(int br, char **line);

#endif