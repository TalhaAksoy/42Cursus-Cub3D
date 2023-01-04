/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:01:13 by faydin            #+#    #+#             */
/*   Updated: 2022/02/07 20:01:17 by faydin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

int     ft_strlenn(char *buf);
char	*get_next_line(int fd);
char	*get_new_line(char *buffer);
char	*first_line(int fd, char *buffer);
char	*strjoin(char *buffer, char *new_buffer);
char	*get_new_buffer(char *buffer);
int		find_nl_char(char *buffer);

#endif
