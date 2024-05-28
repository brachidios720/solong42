/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:08:48 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/28 19:35:45 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void    free_matrice(char **matrice)
{
    int i = 0;
    while(matrice[i])
    {
        free(matrice[i]);
        i++;
    }
    free(matrice);
}

void ft_exit(int i, t_map *map)
{
    if(i == 1)
    {
        ft_printf("T'Y EsT Le BOSS");
    }
    else if(i == 2)
    {
        ft_printf("failure");
    }
    else if(i == 3)
    {
        ft_printf("map is not rectnagle");
    }
    else if(i == 4)
    {
        ft_printf("wall not clean");
    }
    else if(i == 5)
    {
        ft_printf("quit");
    }
    ft_clear(map);
    exit(0);
}

int ft_strlen_int(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return(i);
}

void clear_sprite(t_map *map)
{
    if(map->sprite_collectible)
        mlx_destroy_image(map->mlx, map->sprite_collectible);
    if(map->sprite_exit)
        mlx_destroy_image(map->mlx, map->sprite_exit);
    if(map->sprite_palyer)
        mlx_destroy_image(map->mlx, map->sprite_palyer);
    if(map->sprite_vide)
        mlx_destroy_image(map->mlx, map->sprite_vide);
    if(map->sprite_wall)
        mlx_destroy_image(map->mlx, map->sprite_wall);
}