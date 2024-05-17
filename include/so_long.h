/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:08:52 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/17 17:47:17 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef so_long
#define so_long


#include<unistd.h>
#include<stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "../mlx/mlx.h"



// strcut 

typedef struct s_data
{
    int count_step;
    int collectible;
   int exit;
    
} t_data;

typedef struct s_position
{ 
    int x;
    int y;
                
} t_position;

typedef struct s_map
{
    char **matrice;
    char *filename;
    void *sprite_collectible;
    void *sprite_palyer;
    void *sprite_exit;
    void *sprite_wall;
    void *sprite_vide;
    t_data data_game;
    t_position pos;
    void *mlx_ptr;
    void *win_ptr;
    int win_hight;
    int win_width;
    int image_size;
    void *window;
    void *mlx;
    
    
} t_map;



// map

char **finish_map(char *file);
char **map_alock(char *file);
int line(char *file);
void inis_map(t_map *map, char **av);
void display_map2D(t_map *data);
void add_image(t_map *data);
void render_xpm(t_map *data, int i, int j);
void parcours_map(t_map *data);

//t_map inis_map(t_map *map);

// Utils

void ft_putstr(char *str);
int ft_atoi(char *str);
char *ft_strcpy(char *dest, char *src);

#endif


//1. parsing si map est arguement valides;
//2. implementer l'affichage des maps et sprites;
//3. deplacement du joueur et mise en places des animation;