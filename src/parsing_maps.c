/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:36:55 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/24 17:22:02 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int check_rectangle(t_map *map)
{
    int i = 0;
    int j = 0;
    int len = line(map->filename); 
    while(map->matrice[i])
    {
        while(map->matrice[i][j])
        {
            j++;
        }
        i++;
    }
    j--;
    if(len == j)
        return (1);
    else
        return(0);
}

void ft_error(t_map *map)
{
    int err;

    err = check_rectangle(map);
    if(err == 1)
        ft_exit(2);
}