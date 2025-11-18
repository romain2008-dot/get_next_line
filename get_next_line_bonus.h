/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romgutie <romgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:29:35 by romgutie          #+#    #+#             */
/*   Updated: 2025/11/18 13:29:35 by romgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*extract_line(char *stash);
char	*clean_stash(char *stash);
char	*read_and_join(int fd, char *stash);

size_t	ft_strlen_gnl(const char *s);
char	*ft_strdup_gnl(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr_gnl(const char *s, unsigned int start, size_t len);
char	*ft_strchr_gnl(const char *s, int c);

#endif

