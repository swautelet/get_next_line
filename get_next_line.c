/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:11:55 by simonwautel       #+#    #+#             */
/*   Updated: 2021/11/08 16:19:28 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_first(void)
{
	char	*result;

	result = malloc(sizeof(char));
	*result = '\0';
	return (result);
}

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
	size = BUFFER_SIZE;
	while (size == BUFFER_SIZE)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		result = ft_straddback(result, buffer, size);
		if (ft_end_of_line(result) == 1)
			return (result);
	}
	if (size == 0)
		return (NULL);
	return (result);
}
