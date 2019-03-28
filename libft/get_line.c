/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:45:37 by brfeltz           #+#    #+#             */
/*   Updated: 2019/03/28 14:46:05 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_line(char **temp, int fd, char **line)
{
	char	*str;
	char	*tempmem;

	if ((str = ft_strchr(temp[fd], '\n')))
	{
		tempmem = temp[fd];
		*str = '\0';
		*line = ft_strndup(temp[fd], str - temp[fd]);
		temp[fd] = ft_strdup(str + 1);
		free(tempmem);
		return (1);
	}
	else if (*temp[fd])
	{
		*line = ft_strdup(temp[fd]);
		temp[fd] = ft_strnew(BUFF_SIZE + 1);
		return (1);
	}
	return (0);
}
