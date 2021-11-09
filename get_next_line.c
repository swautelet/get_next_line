/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:11:55 by simonwautel       #+#    #+#             */
/*   Updated: 2021/11/09 21:25:11 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;
	ssize_t		size;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	result = ft_initialize(buffer);
	if (ft_end_of_line(result) == 1)
		return (result);
	size = read(fd, buffer, BUFFER_SIZE);
	if (size == 0 && result[0] != '\0')
		return (result);
	if (size <= 0)
	{
		free (result);
		return (NULL);
	}
	while (size > 0)
	{
		result = ft_straddback(result, buffer, size);
		if (ft_end_of_line(result) == 1)
			return (result);
		size = read(fd, buffer, BUFFER_SIZE);
	}
	return (result);
}
