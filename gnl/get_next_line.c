/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:35:15 by raphaelcarb       #+#    #+#             */
/*   Updated: 2023/08/16 21:13:25 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_read_to_carstock(int fd, char *carstock)
{
	char	*buf;
	ssize_t	res;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (ft_strchr(carstock, '\n') == NULL)
	{
		res = read(fd, buf, BUFFER_SIZE);
		if (res == -1)
		{
			free(buf);
			free(carstock);
			return (NULL);
		}
		if (res == 0)
		{
			free(buf);
			return (carstock);
		}
		buf[res] = '\0';
		carstock = ft_strjoin(carstock, buf);
	}
	free(buf);
	return (carstock);
}

char	*ft_new_carstock(char *carstock)
{
	char	*newboobies;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (carstock[i] != '\n' && carstock[i] != '\0')
		i++;
	k = i;
	if (carstock[i] == '\0' || carstock[i + 1] == '\0')
		return (NULL);
	while (carstock[j + i] != '\0')
		j++;
	newboobies = malloc(sizeof(char) * (j + 1));
	if (newboobies == NULL)
		return (0);
	j = 0;
	i = i + 1;
	while (carstock[i] != '\0')
		newboobies[j++] = carstock[i++];
	newboobies[j] = '\0';
	carstock[k + 1] = '\0';
	return (newboobies);
}

char	*get_next_line(int fd)
{
	static char	*carstock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	carstock = ft_read_to_carstock(fd, carstock);
	if (!(carstock))
		return (0);
	line = carstock;
	carstock = ft_new_carstock(carstock);
	return (line);
}
