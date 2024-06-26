/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:42:09 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/29 16:48:48 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	add_image(t_map *map)
{
	map->sprite_collectible = mlx_xpm_file_to_image(map->mlx,
			"../sprite/Collectibles/star_00.xpm", &map->image_size,
			&map->image_size);
	map->sprite_vide = mlx_xpm_file_to_image(map->mlx,
			"../sprite/Tiles/block.xpm", &map->image_size, &map->image_size);
	map->sprite_exit = mlx_xpm_file_to_image(map->mlx,
			"../sprite/Exit/exit_open_01.xpm", &map->image_size,
			&map->image_size);
	map->sprite_wall = mlx_xpm_file_to_image(map->mlx,
			"../sprite/Ui/uiHeart_off01.xpm", &map->image_size,
			&map->image_size);
	map->sprite_palyer = mlx_xpm_file_to_image(map->mlx,
			"../sprite/Player/idle_00.xpm", &map->image_size, &map->image_size);
	if (!map->sprite_collectible || !map->sprite_exit || !map->sprite_vide
		|| !map->sprite_palyer || !map->sprite_wall)
		exit(EXIT_FAILURE);
}

void	render_xpm(t_map *map, int i, int j)
{
	if (map->matrice[i][j] == '0')
		mlx_put_image_to_window(map->mlx, map->window, map->sprite_vide,
			map->image_size * j, map->image_size * i);
	else if (map->matrice[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->window, map->sprite_wall,
			map->image_size * j, map->image_size * i);
	else if (map->matrice[i][j] == 'P')
		mlx_put_image_to_window(map->mlx, map->window, map->sprite_palyer,
			map->image_size * j, map->image_size * i);
	else if (map->matrice[i][j] == 'C')
		mlx_put_image_to_window(map->mlx, map->window, map->sprite_collectible,
			map->image_size * j, map->image_size * i);
	else if (map->matrice[i][j] == 'E')
		mlx_put_image_to_window(map->mlx, map->window, map->sprite_exit,
			map->image_size * j, map->image_size * i);
}

void	parcours_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->matrice[i])
	{
		j = 0;
		while (map->matrice[i][j])
		{
			render_xpm(map, i, j);
			j++;
		}
		i++;
	}
}
