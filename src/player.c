/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:07:04 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/28 19:36:36 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void add_data(t_map *map)
{
    int i = 0; 
    int j; 
    while (map->matrice[i])
    {
        j = 0;
        while (map->matrice[i][j])
        {
            if(map->matrice[i][j] == 'P')
                ft_player_pos(map, i, j); 
            else if(map->matrice[i][j] == 'C')
                map->collectible++;
            else if(map->matrice[i][j] == 'E')
                map->exit++;
            j++;
        }
        i++;
    }
}

void check(t_map *map, int x, int y)
{
    if(map->matrice[x][y] == 'C' || map->matrice[x][y] == '0' || (map->collectible == 0 && map->matrice[x][y] == 'E'))
    {
        if(map->collectible == 0 && map->matrice[x][y] == 'E')
            ft_exit(1, map);
        else if (map->matrice[x][y] == 'C')
        {
            map->collectible--;
            map->matrice[x][y] = 'P';
            map->matrice[map->pos_x][map->pos_y] = '0';
            map->pos_x = x;
            map->pos_y = y;
        }
        else 
        {
            map->matrice[x][y] = 'P';
            map->matrice[map->pos_x][map->pos_y] = '0';
            map->pos_x = x;
            map->pos_y = y;
        }
    }
}


void  ft_player_pos(t_map *map, int i, int j) 
{
    map->pos_x = i;
    map->pos_y = j;
    map->player++;
}

int move_player(int keycode,t_map *map)
{
    if(keycode == KEY_W)
    {
        check(map, map->pos_x - 1, map->pos_y);
        parcours_map(map);
    }
    else if(keycode == KEY_A)
    { 
        check(map, map->pos_x, map->pos_y - 1);
        parcours_map(map);
    }
    else if(keycode == KEY_S)
    {
        check(map, map->pos_x + 1, map->pos_y);
        parcours_map(map);
    }
    else if(keycode == KEY_D)
    {
        check(map, map->pos_x, map->pos_y + 1);
        parcours_map(map);
    }
    else if(keycode == KEY_ESCAPE)
        ft_exit(5, map);
    ft_printf("number of steps : %d\n", map->count_step++);
    return(0);
}   