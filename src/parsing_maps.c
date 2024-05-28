/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:36:55 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/28 19:23:25 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int check_rectangle(t_map *map)
{
    int i = 0;
    int j = 0;
    int j_tmp = 0;
    while(map->matrice[i])
    {
        j = 0;
        while(map->matrice[i][j])
            j++;
        if((j != j_tmp) && (j_tmp != 0))
            return(1);
        j_tmp = j;
        i++;
    }
    return(0);
}

int check_wall(t_map *map)
{
    size_t x = ft_strlen(map->matrice[0]) - 1;
    size_t y = line(map->filename) - 1;
    size_t i = 0;
    while(i <= x - 1)
    {
        if((map->matrice[0][i] != '1') && (map->matrice[0][i] != '\n'))
            return(1);
        if((map->matrice[y][i] != '1') && (map->matrice[y][i] != '\n'))
            return(1);
        i++;
    }
    i = 0;
    while(i != y)
    {
        if(map->matrice[i][0] != '1' || map->matrice[i][x - 1] != '1')
            return(1);
        i++;
    }
    return(0);
}

void check_flood(t_map *map, int i, int j)
{
    if((map->copie_matrice[i][j] != '0' && map->copie_matrice[i][j] != 'C') && (map->copie_matrice[i][j] != 'E' && map->copie_matrice[i][j] != 'P'))   
        return;
    map->copie_matrice[i][j] = '7';
    check_flood(map, i + 1, j);
    check_flood(map, i - 1, j);
    check_flood(map, i, j + 1);
    check_flood(map, i, j - 1);
}

int si(t_map *map)
{
    int i = 0;
    int j;
    while(map->copie_matrice[i])
    {
        j = 0;
        while(map->copie_matrice[i][j] )
        {
            if(map->copie_matrice[i][j] == '0' || map->copie_matrice[i][j] == 'C' || map->copie_matrice[i][j] == 'E' || map->copie_matrice[i][j] == 'P')
                return(1);
            j++;
        }
        i++;
    }
    return(0);
}

void ft_check_error(t_map *map)
{
    if(check_rectangle(map) == 1)
        ft_exit(3, map);
    if(check_wall(map) == 1)
        ft_exit(4, map);
    if(map->exit != 1)
        ft_exit(2, map);
    if(map->player != 1)
        ft_exit(2, map);
    check_flood(map, map->pos_x, map->pos_x);
    if(si(map) == 1)
        ft_exit(2, map);
    ft_showmap(map->copie_matrice);
    
}