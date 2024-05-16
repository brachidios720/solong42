/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:42:09 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/16 17:49:21 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//#include "get_next_line.h"

// t_map inis_map(t_map *map)
// {
//     map->sprite_collectible = NULL;
//     map->sprite_exit = NULL;
//     map->sprite_palyer = NULL;
//     map->sprite_wall = NULL;
//     map->file = NULL;
//     map->mlx_ptr = NULL;
//     map->win_ptr = NULL;
//     map->pos.x = x;
//     map->pos.y = y;
// }
#include<stdio.h>
#include<stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return(i);
}

char *ft_strcpy(char *src, char *dst)
{
    int i = 0;
    while(src[i])
    {
        dst[i] = src[i];
        i++;
    }
    return(dst);
}

char *stock_tab(char *file, int fd)
{
    int i =0;
    
}
char **fill_to_tab(char *file, int x, int y)
{
    int i = 0;
    int j = 0; 
    char **tab = malloc(sizeof(char *) * x);
    while(tab[i])
    {
        ft_strcpy(file, tab[i]);
        i++;
    }
    return(tab);
    
}

char ft_read_to_car(int i, t_map *game)
{
    size_t res = 0;
    char *buf;
    buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
    res = open(game->filename, O_RDONLY);
    if(res == -1)
        return(NULL);
    
}

int main(void)
{
    int i = 0;
    int x = 6;
    int y = 4;
    
    char **ampp = fill_to_tab("wadfsdf", 1, '\n');
    printf("%s", ampp[i]);
}