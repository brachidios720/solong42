/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:56:40 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/28 19:37:22 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int line(char *file)
{
    int count_line;
    int fd;
    int read_line;
    char stock;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return -1;
    count_line = 1;
    while (1)
    {
        read_line = read(fd, &stock, 1);
        if (read_line == 0)
            break;
        if (read_line < 0)
            return -1;
        if (stock == '\n')
            count_line++;
    }
    close(fd);
    return count_line;
}

char **map_alock(char *file)
{
    char **map;
    int ligne_count;

    ligne_count = line(file);
    if (ligne_count < 0)
        return NULL;
    map = (char **)malloc(sizeof(char *) * (ligne_count + 1));
    if (!map)
    {
        ft_putstr("alloc failed");
        return NULL;
    }
    return map;
}
void    ft_showmap(char **map)
{
    int i = 0;

    while (map[i] != NULL)
    {
        ft_printf("%s", map[i]);
        i++;
    }
    
}

char **finish_map(char *file)
{
    char **map;
    int i = 0;
    int fd;

    map = map_alock(file);
    if (map == NULL)
        return NULL;
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        free(map);
        return NULL;
    }
    while ((map[i] = get_next_line(fd)) != NULL)
        i++;
    map[i] = NULL;
    close(fd);
    return map;
}


