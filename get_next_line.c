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

char	*get_next_line(int fd)
{
	char	*line;

	static char *stash = NULL; // This is my memory box
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
}
