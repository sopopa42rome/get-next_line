/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:08:58 by sopopa            #+#    #+#             */
/*   Updated: 2022/08/21 22:07:25 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strdup(char *str)
{
	int		i;
	char	*final;

	if (!str || !str[0])
	{	
		free(str);
		return (NULL);
	}
	i = 0;
	final = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!final)
		return (0);
	while (str[i])
	{
		final[i] = str[i];
		i++;
	}
	final[i] = '\0';
	free(str);
	return (final);
}
char	*read_and_save(int fd, char *res)
{
	char	*buffer;
	int		num_bytes;
	
	if (!res)
		res = ft_calloc(1, 1);
	buffer = malloc(BUFFER_SIZE + 1* sizeof(buffer));
	num_bytes = 1;
	while (!ft_strchr(res, '\n') && num_bytes != 0)
	{
		num_bytes = read(fd, buffer, BUFFER_SIZE);
		if (num_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[num_bytes] = 0;
		res = ft_strjoin(res, buffer);
	}
	free(buffer);
	return (res);
}

char	*get_first_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	while(save[i] && save[i] != '\n')
		i++;
	line = ft_calloc(i + 2 , sizeof(line));
	i = 0;
	while (save[i] != '\n' && save[i])
	{
		line[i] = save[i];
		i++;	
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	return (line);
}

char	*get_the_next(char *save, char *line)
{
	int		j;
	int		i;
	char	*new_line;

	new_line = ft_calloc(ft_strlen(save) - ft_strlen(line) + 1, sizeof(new_line));
	j = 0;
	i = ft_strlen(line);
	while (save[i] != '\0')
	{
		new_line[j] = save[i];
		i++;
		j++;
		if (new_line[j] == '\n')
		{
			new_line[j] = save[i];
			j++;
		}
	}
	free(save);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*final;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)	
		return (NULL);
	save = read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = get_first_line(save);
	save = get_the_next(save, line);
	final = ft_strdup(line);
	return (final);
}

// int main (void)
// {
// 	int     fd;
// 	char	*z;


// 	fd = open("file.txt", O_RDWR);
// 	z = get_next_line(fd);
// 	printf("%s", z);
// 	z = get_next_line(fd);
// 	printf("%s", z);
// 	z = get_next_line(fd);
// 	printf("%s", z);
	

	
	
	
	

// }
