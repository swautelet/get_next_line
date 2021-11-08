/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:11:55 by simonwautel       #+#    #+#             */
/*   Updated: 2021/10/27 20:20:39 by simonwautel      ###   ########.fr       */
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

	if (fd < 0 || fd > 1023)
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
