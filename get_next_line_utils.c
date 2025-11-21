/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:29:58 by aait-ela          #+#    #+#             */
/*   Updated: 2025/11/18 16:31:03 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	new = malloc(ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	while (*s)
		new[i++] = *(s++);
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		new[i] = s[i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	size_t	i;

	cc = (char)c;
	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (cc == s[i])
			return ((char *)&s[i]);
		i++;
	}
	if (cc == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
