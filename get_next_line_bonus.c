/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:12:06 by aait-ela          #+#    #+#             */
/*   Updated: 2025/11/23 23:27:14 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*append_buffer(char *stash, char *buffer)
{
	char	*new_stash;
	size_t	len1;
	size_t	len2;

	len2 = ft_strlen(buffer);
	if (stash != NULL)
		len1 = ft_strlen(stash);
	else
		len1 = 0;
	new_stash = malloc(len1 + len2 + 1);
	if (!new_stash)
		return (free(stash), NULL);
	if (stash)
	{
		ft_memcpy(new_stash, stash, len1);
		free(stash);
	}
	ft_memcpy(new_stash + len1, buffer, len2);
	new_stash[len1 + len2] = '\0';
	return (new_stash);
}

char	*extract_line(char **stash_ptr)
{
	char	*stash;
	char	*newline;
	char	*line;
	char	*rest;

	stash = *stash_ptr;
	newline = ft_strchr(stash, '\n');
	if (!newline)
	{
		line = ft_strdup(stash);
		free(stash);
		*stash_ptr = NULL;
		return (line);
	}
	line = ft_substr(stash, 0, (newline - stash) + 1);
	rest = ft_strdup(newline + 1);
	if(!rest || !*rest)
		return (free(rest),free(stash), *stash_ptr = NULL, line);
	*stash_ptr = rest;
	free(stash);
	return (line);
}
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash[OPEN_MAX];
	ssize_t		read_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash[fd], '\n'))
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len < 0)
			return(free(buffer),free(stash[fd]), stash[fd] = NULL, NULL);
		if (read_len == 0)
			break ;
		buffer[read_len] = '\0';
		stash[fd] = append_buffer(stash[fd], buffer);
		if (!stash[fd])
			return (free(buffer), NULL);
	}
	free(buffer);
	if (!stash[fd] || *stash[fd] == '\0')
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	return (extract_line(&stash[fd]));
}
