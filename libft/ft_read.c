/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:48:07 by brfeltz           #+#    #+#             */
/*   Updated: 2019/03/28 14:48:33 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
