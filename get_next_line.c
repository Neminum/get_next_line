/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:06:43 by tsurma            #+#    #+#             */
/*   Updated: 2023/12/06 19:27:32 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static t_all_I_need	a;

	while (a.last && a.last[a.len])
		++a.len;
	a.buf = malloc(a.len + BUFFER_SIZE + 1);
	a.toread = read(fd, a.buf + a.len, BUFFER_SIZE);
	if (a.toread < 0)
		return (emergency_shutdown(fd, 0));
	a.buf[a.len + a.toread] = '\0';
	a.lenstore = a.len;
	a.c = -1;
	while (--a.len >= 0)
		a.buf[a.len] = a.last[a.len];
	a.len++;
	while (a.buf[a.len] && a.buf[a.len] != '\n')
		++a.len;
	if (a.buf[a.len] == 0 && a.toread == 0)
		return (emergency_shutdown(fd, 1));
	if (a.buf[a.len] == 0 && a.toread == BUFFER_SIZE)
		return (emergency_shutdown(fd, 2));
	if (a.buf[a.len] == 0 || a.buf[a.len] == '\n' && a.buf[a.len + 1] == 0)

}

char	*emergency_shutdown(int fd, int b)
{
	static t_all_I_need	a;

	a.len = 0;
	if (b == 0 || b == 1)
		free(a.buf);
	if (b != 1)
		free(a.last);
	if (b == 0)
	{
		a.last = NULL;
		return (a.last);
	}
	else if (b == 1)
	{
		a.buf = a.last;
		a.last = NULL;
		return (a.buf);
	}
	else if (b == 2)
	{
		a.last = a.buf;
		return (get_next_line(fd));
	}
	else if (b == 3)
	{
		a.last = NULL;
		return (a.buf);
	}
	if ()
}
