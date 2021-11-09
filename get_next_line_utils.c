/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:11:36 by simonwautel       #+#    #+#             */
/*   Updated: 2021/11/09 18:15:57 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	l;

	l = 1;
	while (str[l])
		l++;
	return (l);
}

char	*ft_straddback(char *result, char *buffer, ssize_t size)
{
	char	*newresult;
	size_t	i;
	size_t	l;

	i = 0;
	newresult = malloc(sizeof(char) * (size + ft_strlen(result) + 1));
	if (!newresult)
	{
		free (result);
		return (NULL);
	}
	while (result[i])
	{
		newresult[i] = result[i];
		i++;
	}
	free (result);
	l = 0;
	while (buffer[l])
	{
		newresult[i + l] = buffer[l];
		l++;
	}
	newresult[i + l] = '\0';
	return (newresult);
}

int	ft_end_of_line(char *str)
{
	while (*str)
	{
		if (*str == '\n')
		{
			str++;
			*str = '\0';
			return (1);
		}
		str++;
	}
	return (0);
}

char	*ft_initialize(char *buffer)
{
	char	*new;
	int		i;
	int		l;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	new = malloc(ft_strlen(&buffer[i]) * sizeof(char));
	if (!new)
		return (NULL);
	i++;
	l = 0;
	while (buffer[i + l])
	{
		new[l] = buffer[i + l];
		buffer[l] = buffer[i + l];
		l++;
	}
	buffer[l] = '\0';
	new[l] = '\0';
	return (new);
}
