/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:23:31 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/21 17:34:59 by rcarbonn         ###   ########.fr       */
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
    map->mlx = mlx_init();
    map->image_size = 32;

    size_t rows = 0;
    size_t cols = 0;
    while (map->matrice[rows])
        rows++;
    if (rows > 0)
        cols = ft_strlen(map->matrice[0]) - 1;

    map->win_hight = rows * map->image_size;
    map->win_width = cols * map->image_size;

    map->window = NULL;
}


int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    t_data *data = malloc(sizeof(t_data));
    t_map *map = malloc(sizeof(t_map));
    if (!map)
        return (1);
    inis_map(map, av);
    add_image(map);
    parcours_map(map);
    add_data(map, data);
    mlx_key_hook(map->window, move_player, map);
    mlx_loop(map->mlx);
    free_matrice(map->matrice);
}