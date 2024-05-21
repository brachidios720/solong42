/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:07:04 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/21 17:54:15 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void add_data(t_map *map, t_data *data)
{
    int i = 0;
    int j;
    while (map->matrice[i])
    {
        j = 0;
        while (map->matrice[i][j])
        {
            if(map->matrice[i][j] == 'P')
                ft_player_pos(map, data, i, j);
            else if(map->matrice[i][j] == 'C')
                data->collectible++;
            else if(map->matrice[i][j] == 'E')
                data->exit++;
            j++;
        }
        i++;
    }
}

void  ft_player_pos(t_map *map,t_data *data, int i, int j)
{
    map->pos_x = i;
    map->pos_y = j;
    data->player++;
}

int move_player(t_map *map, int keycode)
{
    if(keycode == KEY_W)
        map->matrice[map->pos_x][map->pos_x] = map->matrice[map->pos_x + 1][map->pos_y];
    else if(keycode == KEY_A)
        map->matrice[map->pos_x][map->pos_y] = map->matrice[map->pos_x][map->pos_y - 1];
    else if(keycode == KEY_S)
        map->matrice[map->pos_x][map->pos_y] = map->matrice[map->pos_x - 1][map->pos_y];
    else if(keycode == KEY_D)
        map->matrice[map->pos_x][map->pos_y] = map->matrice[map->pos_x][map->pos_y + 1];
    parcours_map(map);
    return(1);
}   