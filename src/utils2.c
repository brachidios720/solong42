/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:27:51 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/29 19:59:41 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_with_cross(t_map *map)
{
	ft_clear(map);
	return (0);
}

void	ft_clear(t_map *map)
{
	if (map)
	{
		if (map->matrice)
			free_matrice(map->matrice);
		if (map->copie_matrice)
			free_matrice(map->copie_matrice);
		clear_sprite(map);
		if (map->window)
			mlx_destroy_window(map->mlx, map->window);
		if (map->mlx)
		{
			mlx_destroy_display(map->mlx);
			free(map->mlx);
		}
	}
	exit(0);
}

void	ft_clear2(t_map *map)
{
	if (map)
	{
		if (map->matrice)
			free_matrice(map->matrice);
		if (map->copie_matrice)
			free_matrice(map->copie_matrice);
	}
}

int	check_elements_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->matrice[i])
	{
		j = 0;
		while (map->matrice[i][j])
		{
			if (map->matrice[i][j] != '1' && map->matrice[i][j] != 'C'
				&& map->matrice[i][j] != '0' && map->matrice[i][j] != 'E'
				&& map->matrice[i][j] != 'P' && map->matrice[i][j] != '\n'
				&& map->matrice[i][j] != '\0' && map->matrice[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_exit2(int i, t_map *map)
{
	if (i == 1)
	{
		ft_printf("T'Y EsT Le BOSS");
	}
	else if (i == 2)
	{
		ft_printf("failure");
	}
	else if (i == 5)
	{
		ft_printf("quit");
	}
	ft_clear(map);
	exit(0);
}
