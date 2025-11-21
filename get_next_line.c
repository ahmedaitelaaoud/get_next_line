/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:59:39 by aait-ela          #+#    #+#             */
/*   Updated: 2025/11/18 13:59:39 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_and_free(char *stored, char *buffer)
{
	char	*old_stored;
	int		total_len;

	old_stored = NULL;
	if (stored)
	{
		old_stored = ft_strdup(stored);
		free(stored);
		total_len = ft_strlen(old_stored) + ft_strlen(buffer);
		stored = (char *)malloc(total_len + 1);
		if (!stored)
			return (free(old_stored), NULL);
		ft_memcpy(stored, old_stored, ft_strlen(old_stored));
		ft_memcpy(stored + ft_strlen(old_stored), buffer, ft_strlen(buffer));
		stored[total_len] = '\0';
		free(old_stored);
	}
	else
		stored = ft_strdup(buffer);
	return (stored);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			index;

	if (!dest || !src)
		return (NULL);
	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	index = 0;
	while (index < n)
	{
		destination[index] = source[index];
		index++;
	}
	return (dest);
}

void	update_remainder(char **stored_ptr)
{
	char	*after_newline;
	char	*old_stored;

	old_stored = *stored_ptr;
	after_newline = ft_strdup(ft_strchr(*stored_ptr, '\n') + 1);
	if (!after_newline || *after_newline == '\0')
	{
		free(after_newline);
		*stored_ptr = NULL;
	}
	else
		*stored_ptr = after_newline;
	free(old_stored);
}

char	*extract_line(char **stored_ptr, char **buffer_ptr, ssize_t eof_flag)
{
	char	*current_line;

	current_line = NULL;
	if (*stored_ptr && **stored_ptr && eof_flag == 0)
	{
		current_line = ft_strdup(*stored_ptr);
		free(*stored_ptr);
		*stored_ptr = NULL;
		if (*buffer_ptr)
			free(*buffer_ptr);
		*buffer_ptr = NULL;
		return (current_line);
	}
	if (*stored_ptr && ft_strchr(*stored_ptr, '\n') != NULL)
	{
		current_line = ft_substr(*stored_ptr, 0, (ft_strlen(*stored_ptr))
				- ft_strlen(ft_strchr(*stored_ptr, '\n')) + 1);
		update_remainder(stored_ptr);
		return (current_line);
	}
	free(*stored_ptr);
	*stored_ptr = NULL;
	if (*buffer_ptr)
		free(*buffer_ptr);
	return (*buffer_ptr = NULL, NULL);
}

char	*get_next_line(int fd)
{
	char		*read_buffer;
	ssize_t		bytes_read;
	static char	*leftover_text;
	char		*updated_leftover;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (ft_strchr(leftover_text, '\n') != NULL)
			return (extract_line(&leftover_text, &read_buffer, 1));
		read_buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!read_buffer)
			return (free(leftover_text), leftover_text = NULL, NULL);
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		read_buffer[bytes_read] = '\0';
		updated_leftover = join_and_free(leftover_text, read_buffer);
		free(read_buffer);
		if (!updated_leftover)
			return (leftover_text = NULL, NULL);
		leftover_text = updated_leftover;
	}
	return (extract_line(&leftover_text, &read_buffer, 0));
}
