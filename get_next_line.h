/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:05:32 by aait-ela          #+#    #+#             */
/*   Updated: 2025/11/18 16:47:33 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#   define BUFFER_SIZE 5
# endif

# if BUFFER_SIZE <= 0
#   undef BUFFER_SIZE 
#   define BUFFER_SIZE 0
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_verify(char *tmp, char *buff);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_line_and_free(char **ptr_tmp, char **ptr_buff, ssize_t b);

#endif
