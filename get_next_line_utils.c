/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:01:37 by muteza            #+#    #+#             */
/*   Updated: 2021/11/26 18:44:58 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#ifndef BUFF_SIZE
# define BUFF_SIZE 40
#endif 

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		lens1;
	int		lens2;
	char	*str;
	//printf("aa");
	if (s1 && s2)
	{
		lens1 = ft_strlen((char *)s1);
		lens2 = ft_strlen((char *)s2);
		str = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[lens1] = s2[i];
			lens1++;
		}
		str[lens1] = '\0';
		return (str);
	}
	return (NULL);
}
/*
int	ft_strchr(const char *s, int c)
{
	size_t	i;

	if (c == 0)
		return (0);
	i = 0;
	while (s[i++] && c != 0)
		if (s[i] == (char)c)
			return (i);
	//printf("ret 0");
	return (-1);
}
*/

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (c == 0)
		return ((char *) s + ft_strlen((char *)s));
	i = -1;
	while (s[++i] && c != 0)
		if (s[i] == (char)c)
			return ((char *)(s + i));
	return (NULL);
}
