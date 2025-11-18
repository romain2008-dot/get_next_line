/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romgutie <romgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:29:15 by romgutie          #+#    #+#             */
/*   Updated: 2025/11/18 13:29:17 by romgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*extract_line(char *stash)
{
	char	*line;
	size_t	i;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr_gnl(stash, 0, i);
	return (line);
}

char	*clean_stash(char *stash)
{
	char	*new;
	size_t	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new = ft_strdup_gnl(stash + i + 1);
	free(stash);
	return (new);
}

char *read_and_join(int fd, char *stash)
{
    char *buffer;
    ssize_t bytes;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    bytes = 1;
    while (bytes > 0 && (!stash || !ft_strchr_gnl(stash, '\n')))
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes < 0)
        {
            free(buffer);
            free(stash);
            return (NULL);
        }
        buffer[bytes] = '\0';
        stash = ft_strjoin_gnl(stash, buffer);
    }
    free(buffer);
    return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_and_join(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}
