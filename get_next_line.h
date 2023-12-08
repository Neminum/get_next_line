/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:06:41 by tsurma            #+#    #+#             */
/*   Updated: 2023/12/06 16:01:50 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

char	*get_next_line(int fd);

typedef struct all_I_need
{
	char	*last;
	char	*buf;
	ssize_t	toread;
	int		lenstore;
	int		c;
	int		len;
}	t_all_I_need;

#endif
