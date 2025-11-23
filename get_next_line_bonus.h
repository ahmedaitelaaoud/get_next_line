/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:13:33 by aait-ela          #+#    #+#             */
/*   Updated: 2025/11/23 23:25:23 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# if BUFFER_SIZE <= 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*extract_line(char **stash_ptr);
char	*append_buffer(char *stash, char *buffer);

#endif
