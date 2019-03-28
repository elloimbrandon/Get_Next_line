/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:49:00 by brfeltz           #+#    #+#             */
/*   Updated: 2019/03/28 14:49:16 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	static char *temp[4864];

	if (!line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	if (ft_read(fd, &temp[fd]) < 0)
		return (-1);
	if (get_line(&temp[fd], fd, line) == 1)
		return (1);
	return (0);
}
