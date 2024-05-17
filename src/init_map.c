/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:42:09 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/17 17:47:10 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void inis_map(t_map *map, char **av)
{
    map->sprite_collectible = NULL;
    map->sprite_exit = NULL;
    map->sprite_palyer = NULL;
    map->sprite_wall = NULL;
    map->sprite_vide = NULL;
    map->filename = av[1];
    map->matrice = finish_map(map->filename);
    map->mlx_ptr = 0;
    map->win_ptr = 0;
}

void add_image(t_map *data)
{
    data->image_size = 50;
    data->win_hight = data->image_size * data->win_hight;
    data->win_width = data->image_size * data->win_width;
    data->sprite_collectible = mlx_xpm_file_to_image(data->mlx, "../sprite/Collectibles/star_00.xpm", &data->win_width, &data->win_hight);
    data->sprite_vide = mlx_xpm_file_to_image(data->mlx, "../sprite/Tiles/block.xpm", &data->win_width, &data->win_hight);
    data->sprite_exit = mlx_xpm_file_to_image(data->mlx, "../sprite/Exit/exit_open_01.xpm", &data->win_width, &data->win_hight);
    data->sprite_wall = mlx_xpm_file_to_image(data->mlx, "../sprite/Ui/uiHeart_off01.xpm", &data->win_width, &data->win_hight);
    data->sprite_palyer = mlx_xpm_file_to_image(data->mlx, "../sprite/Player/idle_00.xpm", &data->win_width, &data->win_hight);
    // if(!data->sprite_collectible || !data->sprite_exit || !data->sprite_vide || !data->sprite_palyer || !data->sprite_wall)
    //     return(1);
    // return(0);      
}

void render_xpm(t_map *data, int i, int j)
{
    if(data->matrice[i][j] == '1')
        mlx_put_image_to_window(data->mlx, data->window, data->sprite_wall, data->image_size * i, data->image_size * j);
    else if(data->matrice[i][j] == '0')
        mlx_put_image_to_window(data->mlx, data->window, data->sprite_vide, data->image_size * i, data->image_size * j);
    else if(data->matrice[i][j] == 'P')
        mlx_put_image_to_window(data->mlx, data->window, data->sprite_palyer, data->image_size * i, data->image_size * j);
    else if(data->matrice[i][j] == 'C')
        mlx_put_image_to_window(data->mlx, data->window, data->sprite_collectible, data->image_size * i, data->image_size * j);
    else if(data->matrice[i][j] == 'E')
        mlx_put_image_to_window(data->mlx, data->window, data->sprite_exit, data->image_size * i, data->image_size * j);
}

void parcours_map(t_map *data)
{
    int i = -1;
    int j = -1;
    while(data->matrice[++i][j])
    {
        while(data->matrice[i][++j])
            render_xpm(data, i, j);
            
    }
}