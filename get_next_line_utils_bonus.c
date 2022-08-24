/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:09:01 by sopopa            #+#    #+#             */
/*   Updated: 2022/08/18 14:10:34 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return ((char *)(str + i));
		}
		i++;
	}
	if (str[i] == c)
	{
		return ((char *)(str + i));
	}
	return (NULL);
}

void	*ft_calloc(size_t num_elements, size_t size)
{
	void	*ptr;

	ptr = malloc(num_elements * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (num_elements * size));
	return (ptr);
}

void	ft_bzero(void *str, size_t len)
{
	unsigned int	i;
	unsigned char	*conv;

	i = 0;
	conv = (unsigned char *)str;
	while (i < len)
	{
		conv[i] = 0;
		i++;
	}
	str = conv;
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}
