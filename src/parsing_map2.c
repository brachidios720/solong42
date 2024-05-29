/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:09:56 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/29 19:45:23 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_extension(t_map *map)
{
	size_t	i;

	i = ft_strlen(map->filename);
	if (map->filename[i - 1] != 'r' || map->filename[i - 2] != 'e'
		|| map->filename[i - 3] != 'b' || map->filename[i - 4] != '.')
		return (1);
	return (0);
}
