/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:06:41 by tsurma            #+#    #+#             */
/*   Updated: 2023/12/13 19:35:44 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);

typedef struct all_I_need
{
	char	*last;
	char	*buf;
	ssize_t	toread;
	int		lenstore;
	int		c;
	int		len;
}	t_all_I_need;

char	*returns(t_all_I_need *a);
char	*returns1(t_all_I_need *a);
char	*returns2(t_all_I_need *a);
void	store(t_all_I_need *a);
char	*store1(t_all_I_need *a);

#endif
