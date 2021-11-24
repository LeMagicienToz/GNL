/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:50:25 by muteza            #+#    #+#             */
/*   Updated: 2021/11/22 15:55:14 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
//char	*check_error(int fd, char *buff);
char	*inibuff(int fd, char *buff);
char	*reroll_buff(char *buff, int len_line);
char	*get_line(char *buff);

int		ft_strchr(const char *s, int c);

size_t	ft_strlen(char *s);

#endif