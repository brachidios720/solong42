/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:23:31 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/20 19:15:07 by rcarbonn         ###   ########.fr       */
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
    t_map *dat = malloc(sizeof(t_map));
    if (!dat)
        return (1);
    inis_map(dat, av);
    add_image(dat);
    parcours_map(dat);
    mlx_loop(dat->mlx);
    free_matrice(dat->matrice);
}