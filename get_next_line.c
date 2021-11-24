/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:52:00 by muteza            #+#    #+#             */
/*   Updated: 2021/11/24 17:47:36 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#ifndef BUFF_SIZE
# define BUFF_SIZE 60
#endif 

char	*get_next_line(int fd)
{
	static char		*buff;
	char			*line;
	int				len_line;
	char			*temp_buff;

	buff = inibuff(fd, buff);
	//printf(buff);
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	//printf(buff);
	line = get_line(buff);
	len_line = ft_strlen(line);
	//printf("%i\n", len_line);
	temp_buff = buff;
	buff = 0;
	//printf("%s", buff);
	buff = reroll_buff(temp_buff, len_line + 1);
	//printf("%s", buff);
	//printf("%s", buff);
	return (line);
}

/*char	*check_error(int fd, char *buff)
{
	char	*buff_tempo;

	buff_tempo = malloc(BUFF_SIZE);
	if (buff != 0)
		buff_tempo = buff;
	if (read(fd, buff_tempo, BUFF_SIZE) < 0)
		return (NULL);
	if (BUFF_SIZE <= 0)
		return (NULL);
	return (inibuff(fd, buff_tempo));
}*/

char	*inibuff(int fd, char *buff)
{
	char	*tempo_test;
	char	*test;
	int		nb;

	test = malloc(BUFF_SIZE);
	nb = read(fd, test, BUFF_SIZE);
	tempo_test = test;
	//printf("%s", test);
	if (nb > 0 && buff == 0)
	{
		free(test);
		//printf("%s", test);
		return (test);
	}
	if (buff != 0)
	{
		free(test);
		return (buff);
	}
	free(test);
	return (NULL);
}

char	*reroll_buff(char *buff, int len_line)
{
	int		i;
	char	*n_buff;
	char	*tmp_buff;

	i = 0;
	tmp_buff = buff;
	//printf("%s", buff);
	//printf("%s", buff);
	n_buff = malloc(BUFF_SIZE);
	while (tmp_buff[len_line] != '\0')
	{
		//printf("A");
		n_buff[i++] = buff[len_line++];
	}
	//free(n_buff);
	//printf("%s", n_buff);
	return (n_buff);
}

char	*get_line(char *buff)
{
	char	*str;
	char	*str_tmp;
	int		i;

	str = malloc(BUFF_SIZE);
	//buff_tmp = buff;
	//printf(buff);
	i = 0;
	//str = malloc(BUFF_SIZE);
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		//printf("%c", str[i]);
		str[i] = buff[i];
		++i;
	}
	str_tmp = str;
	free(str);
	//printf("%s", buff);
	return (str_tmp);
}
/*
int	main(void)
{
	int	fd;

	fd = open("abc.txt", O_RDONLY);
	//get_next_line(fd);
	//get_next_line(fd);
	get_next_line(fd);
	//get_next_line(fd);
	//printf("%s", get_next_line(fd));
}
*/