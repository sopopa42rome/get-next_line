/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:08:58 by sopopa            #+#    #+#             */
/*   Updated: 2022/08/24 23:08:46 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_and_save(int fd, char *res)
{
	char	*buffer;
	int		num_bytes;
	
	if (!res)
		res = ft_calloc(1, 1);
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(buffer));
	num_bytes = 1;
	while (!ft_strchr(res, '\n') && num_bytes != 0)
	{
		num_bytes = read(fd, buffer, BUFFER_SIZE);
	if (num_bytes == -1 || (num_bytes == 0 && res[0] == 0))
		{
			free(buffer);
			free(res);
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

	if (!save)

		return (NULL);
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
	static char	*save[257];
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)	
		return (NULL);
	save[fd] = read_and_save(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = get_first_line(save[fd]);
	save[fd] = get_the_next(save[fd], line);
	return (line);
}