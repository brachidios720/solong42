/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:08:52 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/15 17:38:40 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef so_long
#define so_long

#include<unistd.h>
#include<stdlib.h>
#include <fcntl.h>


// strcut 

typedef struct s_map
{
    void **file;
    void *sprite_collectible;
    void *sprite_palyer;
    void *sprite_exit;
    void *sprite_wall;
    t_game_data data_game;
    t_position pos;
    void *mlx_ptr;
    void *win_ptr;
    
} t_map;

typedef struct s_game_data
{
    int count_step;
    int collectible;
    int exit;
    
} t_game_data;

typedef struct s_position
{
    int *pos_x;
    int *pos_y;
    int init_pos;
            
} t_position;

// map

t_map inis_map(t_map *map);

// Utils

void ft_putstr(char *str);
int ft_atoi(char *str);

#endif


//1. parsing si map est arguement valides;
//2. implementer l'affichage des maps et sprites;
//3. deplacement du joueur et mise en places des animation;