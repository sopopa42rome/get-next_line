/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:08:58 by sopopa            #+#    #+#             */
/*   Updated: 2022/08/20 22:12:13 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_save(int fd, char *res)
{
	char	*buffer;
	int		num_bytes;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
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
	i = ft_strlen(save);
	if (!save)
		return (NULL);
	line = ft_calloc(i + 2, sizeof(char));
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
	line[i] = '\0';
	return (line);
}

char	*get_the_next(char *save, int i)
{
	int		j;
	char	*new_line;

	new_line = ft_calloc(ft_strlen(save) - i + 1, sizeof(char));
	j = 0;
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
	new_line[j] = '\0';
	free(save);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_and_save(fd, save);
	if (!save || !save[0])
	{
		return (NULL);
	}
	line = get_first_line(save);
	save = get_the_next(save, ft_strlen(line));
	return (line);
}

// int main (void)
// {
// 	int     fd;
// 	char    *z;
// 	fd = open("file.txt", O_RDWR);
	z
// 	// z = get_next_line(fd);
// 	printf("String = %s\n", get_next_line(fd));
	
		
// }
