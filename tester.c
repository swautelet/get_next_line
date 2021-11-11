/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:09:17 by swautele          #+#    #+#             */
/*   Updated: 2021/11/11 18:09:29 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*r;
	int		c;

	c = 1;
	fd = open("coucou", O_RDWR);
	r = get_next_line(fd);
	printf("%d	%s", c, r);
	free (r);
	while (r)
	{
		c++;
		r = get_next_line(fd);
		printf("%d	%s", c, r);
		free (r);
	}
}
