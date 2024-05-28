/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:23:31 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/28 19:16:34 by rcarbonn         ###   ########.fr       */
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
    map->copie_matrice = finish_map(map->filename);
    map->collectible = 0;
    map->exit = 0;
    map->player = 0;
    map->count_step = 0;
    map->pos_x= 0;
    map->pos_y = 0;
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

    //changement
    
    if (ac != 2)
        return (0);
    t_map map;
    inis_map(&map, av);
    add_data(&map);
    ft_check_error(&map);
    map.mlx = mlx_init();
    map.window = mlx_new_window(map.mlx, map.win_width, map.win_hight, "so_long");
    if (map.window == NULL)
        exit(EXIT_FAILURE);
    add_image(&map);
    parcours_map(&map);
    mlx_key_hook(map.window, move_player, &map);
    mlx_hook(map.window, 33, 1L << 22, close_with_cross, &map);
    mlx_loop(map.mlx);
    ft_clear(&map);

    /*
    if (ac != 2)
        return (0);
    t_map *map = malloc(sizeof(t_map));
    if (!map)
        return (0);
    printf("TEST\n");
    inis_map(map, av);
    map->mlx = mlx_init();
    map->window = mlx_new_window(map->mlx, map->win_width, map->win_hight, "so_long");
    if (map->window == NULL)
        exit(EXIT_FAILURE);
    add_image(map);
    add_data(map);
    parcours_map(map);
    //mlx_hook(map->window, 2, 1L << 0, move_player, &map);
    mlx_key_hook(map->window, move_player, &map);
    printf("TESTlast\n");
    mlx_loop(map->mlx);
    free_matrice(map->matrice);*/
}