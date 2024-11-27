/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadiaman <yadiaman@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:13:42 by yadiaman          #+#    #+#             */
/*   Updated: 2024/11/22 13:17:30 by yadiaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_fd(int fd, char *aux_line);
char	*ft_get_line(char *aux_line);
char	*ft_remove_line(char *aux_line);

char *get_next_line(int fd)
{
	static char *aux_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0)
	{
		free (aux_line);
		aux_line = NULL;
		return (NULL);
	}
	aux_line = ft_read_fd(fd, aux_line);
	if (!aux_line)
		return (NULL);
	line = ft_get_line(aux_line);
	aux_line = ft_remove_line(aux_line);
	if (!line)
		free (aux_line);
	return (line);
}

char *ft_read_fd( int fd, char *aux_line)
{
	char *buffer;
	int read_bytes;
	char *save_aux;
	
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if(!buffer)
		return (NULL);
	read_bytes = 1;
	while(!ft_stchr(buffer, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if(read_bytes == -1)
		{
			free(aux_line);
			aux_line = NULL;
			return (NULL);
		}
		save_aux = aux_line;
		aux_line = ft_strjoin(save_aux, buffer, read_bytes);
	}
	free(buffer);
	if (ft_strlen(aux_line) == 0)
		return(free (aux_line), NULL);
	return(aux_line);
}
