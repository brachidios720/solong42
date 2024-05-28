/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:04:16 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/28 19:14:54 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int close_with_cross(t_map *map)
{
    ft_clear(map);
    return(0);
}

void ft_clear(t_map *map)
{
    if(map)
    {
        if(map->matrice)
            free_matrice(map->matrice);
        if(map->copie_matrice)
            free_matrice(map->copie_matrice);
        clear_sprite(map);
        if(map->window)
            mlx_destroy_window(map->mlx, map->window);
        if(map->mlx)
        {
            mlx_destroy_display(map->mlx);
            free(map->mlx);
        }
        //free(map);
    }
    exit(0);
}