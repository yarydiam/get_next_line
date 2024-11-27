/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadiaman <yadiaman@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:13:28 by yadiaman          #+#    #+#             */
/*   Updated: 2024/11/22 13:17:03 by yadiaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *aux_line, char *buffer, int read_bytes);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char	*ft_read_fd(int fd, char *aux_line);
char	*ft_get_line(char *aux_line);
char	*ft_remove_line(char *aux_line);
char	*ft_strchr(const char *s, int c);

#endif