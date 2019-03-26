/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:07:14 by brfeltz           #+#    #+#             */
/*   Updated: 2019/03/25 20:24:41 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_line(char **temp, int fd, char **line)
{
	char	*str;
	char	*tempmem;

	if ((str = ft_strchr(temp[fd], '\n')))
	{
		tempmem = temp[fd];
		*str = '\0';
		*line = ft_strdup(temp[fd]);
		temp[fd] = ft_strdup(str + 1);
		ft_strdel(&tempmem);
		return (1);
	}
	else if (*temp[fd])
	{
		*line = ft_strdup(temp[fd]);
		ft_strdel(&temp[fd]);
		return (1);
	}
	return (0);
}

int		ft_read(int fd, char **buffer)
{
	char	*temp;
	char	*leak;
	int		result;

	temp = ft_strnew(BUFF_SIZE);
	while ((result = read(fd, temp, BUFF_SIZE)) > 0)
	{
		leak = buffer[fd];
		buffer[fd] = ft_strjoin(buffer[fd], temp);
		if (!buffer[fd])
			buffer[fd] = ft_strdup(temp);
		free(leak);
		ft_bzero(temp, BUFF_SIZE);
	}
	free(temp);
	return (result);
}

int		get_next_line(const int fd, char **line)
{
	static	char	*buff[4864];

	if (!line || fd < 0 || BUFF_SIZE < 0 || ft_read(fd, &buff[fd]))
		return (-1);
	if (get_line(&buff[fd], fd, line))
		return (1);
	return (0);
}

#include <stdio.h>
int main()
{
  int fd;
  char *line = NULL;

  fd = open("file.txt", O_RDONLY);
  while (get_next_line(fd, &line))
    printf("%s\n", line);
  return (0);
}
