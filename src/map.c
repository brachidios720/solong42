/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:56:40 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/16 19:53:47 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../gnl/get_next_line.h"

char *ft_strcpy(char *dest, char *src)
{
    int i = 0;
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return(dest);
}

void ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int line(char *file)
{
    int count_line;
    int fd;
    int read_line;
    char stock;

    fd = open(file, O_RDONLY);
    if(!fd)
        return(-1);
    count_line = 1;
    while(1)
    {
        read_line = read(fd, &stock, 1);
        if(read_line == 0)
            return(0);
        if(read_line < 0)
            return(-1);
        if(stock == '\n')
            count_line++;
    }
    close(fd);
    return(count_line);
}

char **map_alock(char *file)
{
    char **map;
    int ligne_count;

    ligne_count = line(file);
    if(ligne_count >= 0)
        return(NULL);
    map = malloc(sizeof(char *) * ligne_count + 1);
    if(!map)
    {
        ft_putstr("alloc failed");
        return(0);
    }
    return(map);
}

char **finish_map(char *file)
{
    char **map;
    int i = 0;
    int fd;
    int count = line(file);
    
    map = map_alock(file);
    if(map == NULL)
        return(NULL);
    fd = open(file, O_RDONLY);
    while(get_next_line(fd))
        ;
    map[i] = NULL;
    close(fd);
    return(map);   
}


int main(void)
{
    char *map = "../map/map2.ber";
    char **tab = finish_map(map);
    int  i = 0;
    while(tab[i])
    {
        printf("%s", tab[i]);
        i++;
    }
}