/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:08:48 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/22 16:38:56 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return(res);
}

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

void ft_exit(int i)
{
    if(i == 1)
    {
        printf("sucess");
        exit(1);
    }
    else if(i == 2)
    {
        printf("failure");
        exit(0);
    }
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