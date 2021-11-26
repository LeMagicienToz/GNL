/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:52:00 by muteza            #+#    #+#             */
/*   Updated: 2021/11/26 18:45:25 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 41
#endif 

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*save;
	char		*line;
	int			ret;

	ret = read(fd, buff, BUFFER_SIZE);
	//printf("%s", buff);
	line = get_line(save, buff, ret);
	//len_line = ft_strlen(line + 1);
	//buff = reroll_buff(temp_buff, pos + 1);
	return (line);
}

char	*get_line(char *save, char *buff, int ret)
{
	save = malloc(BUFFER_SIZE);
	while (ret > 0 && !ft_strchr(save, '\n'))
	{
		//printf("aa");
		ft_strjoin(save, buff);
	}
	printf("%s", save);
	return (save);
}
/*
char	*getpos(char *buff, int pos)
{
	//char	*save;
	char	*line;
	int		i;

	i = 0;
	line = malloc (sizeof(char) * pos + 1);
	while (i <= pos)
	{
		line[i] = buff[i];
		i++;
	}
	//printf("%d", pos);
	if (pos == -1)
	{
		line = buff;
		//printf(line);
		return (line);
	}
	line[i] = 0;
	//save = ft_strdup(buff + pos + 1);
	//free(buff);
	//buff = ft_strdup(save);
	return (line);
}

char	*inibuff(int fd, char *buff)
{
	char	*test;
	int		nb;

	test = malloc(BUFF_SIZE);
	nb = read(fd, test, BUFF_SIZE);
	//printf("%d", nb);
	test[nb] = 0;
	//printf("%c", test[nb]);
	if(test != 0)
	{
	if (nb > 0 && buff == 0)
		{
			//free(test);
			return (test);
		}
		if (buff != 0)
		{
			free(test);
			return (buff);
		}
	}
	free(test);
	return (NULL);
}*/
/*
char	*reroll_buff(char *buff, int posn)
{
	int		i;
	char	*n_buff;
	char	*tmp_buff;


	printf("%s", n_buff);
	return (n_buff);
}*/

#include <stdio.h>
int	main(void)
{
	int	fd;

	fd = open("abc.txt", O_RDONLY);
	//get_next_line(fd);
	//get_next_line(fd);
	printf("%s", get_next_line(fd));
	//char *tmp;
	//tmp = get_next_line(fd);
	/*while (tmp)
	{
		printf("%s\n", tmp);
		tmp = get_next_line(fd);
	}*/
}
