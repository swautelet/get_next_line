/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:01:05 by simonwautel       #+#    #+#             */
/*   Updated: 2021/11/11 22:01:06 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*gnl(char *result, char *buffer, int size, int fd)
{
	while (size > 0)
	{
		result = ft_straddback(result, buffer, size);
		if (ft_end_of_line(result) == 1)
			return (result);
		size = read(fd, buffer, BUFFER_SIZE);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*result;
	ssize_t		size;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	result = ft_initialize(buffer[fd]);
	if (!result)
		return (NULL);
	if (ft_end_of_line(result) == 1)
		return (result);
	size = read(fd, buffer[fd], BUFFER_SIZE);
	if (size == 0 && result[0] != '\0')
		return (result);
	if (size <= 0)
	{
		free (result);
		return (NULL);
	}
	result = gnl(result, buffer[fd], size, fd);
	return (result);
}
