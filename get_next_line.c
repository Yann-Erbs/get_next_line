/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:16:57 by yerbs             #+#    #+#             */
/*   Updated: 2023/11/13 09:56:57 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check(int br, char **line)
{
	if (br == -1 || !(*line) || (*line)[0] == '\0')
	{
		free(*line);
		return (0);
	}
	return (1);
}

void	ft_update(char **line, char *buffer)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	len = ft_strlen(*line + i + 1);
	ft_memmove(buffer, *line + i + 1, len);
	buffer[len] = '\0';
	if ((*line)[i] == '\n')
	{
		tmp = ft_substr(*line, 0, i + 1);
		if (!tmp)
			return ;
		free(*line);
		*line = tmp;
	}
}

void	ft_read(int fd, char **line, char *buffer, int *br)
{
	*br = 1;
	while (!ft_strchr(buffer, '\n') && *br != 0)
	{
		*br = read(fd, buffer, BUFFER_SIZE);
		if (*br == -1)
		{
			buffer[0] = '\0';
			free(*line);
			*line = NULL;
			return ;
		}
		buffer[*br] = '\0';
		*line = ft_strjoin(*line, buffer);
		if (!*line)
			return ;
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			br;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (buffer[0] != '\0')
		line = ft_strjoin(NULL, buffer);
	ft_read(fd, &line, buffer, &br);
	if (!ft_check(br, &line))
		return (NULL);
	if (br == 0)
		return (line);
	ft_update(&line, buffer);
	return (line);
}
