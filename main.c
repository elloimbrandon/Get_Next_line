/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:51:42 by brfeltz           #+#    #+#             */
/*   Updated: 2019/04/16 14:52:33 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
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
