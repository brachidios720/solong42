/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:42:09 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/15 17:04:01 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


t_map inis_map(t_map *map)
{
    map->sprite_collectible = NULL;
    map->sprite_exit = NULL;
    map->sprite_palyer = NULL;
    map->sprite_wall = NULL;
    map->file = NULL;
    map->mlx_ptr = NULL;
    map->win_ptr = NULL;
}

