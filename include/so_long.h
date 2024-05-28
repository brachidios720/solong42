/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:08:52 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/28 19:34:54 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef so_long
#define so_long

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESCAPE 65307
#include<unistd.h>
#include<stdlib.h>
#include <fcntl.h>
#include "../mlx/mlx.h"
#include "../gnl/get_next_line.h"
#include "../printf/src/ft_printf.h"




// strcut 


typedef struct s_map
{
    char **matrice;
    char **copie_matrice;
    char *filename;
    void *sprite_collectible;
    void *sprite_palyer;
    void *sprite_exit;
    void *sprite_wall;
    void *sprite_vide;
    int win_hight;
    int win_width;
    int image_size;
    void *window;
    void *mlx;
    int pos_x;
    int pos_y;    
    int count_step;
    int collectible;
    int exit;
    int player;
    
    
    
} t_map;

// parse map

int check_rectangle(t_map *map);
void ft_check_error(t_map *map);
int check_wall(t_map *map);
void check_flood(t_map *map, int i, int j);

// map

char **finish_map(char *file);
char **map_alock(char *file);
int line(char *file);
void inis_map(t_map *map, char **av);
void display_map2D(t_map *data);
void add_image(t_map *data);
void render_xpm(t_map *data, int i, int j);
void parcours_map(t_map *data);
void clear_sprite(t_map *map);
void ft_showmap(char **map);

// player_move

void add_data(t_map *map);
int move_player(int keycode,t_map *map);
void  ft_player_pos(t_map *map, int i, int j);


// Utils

int ft_atoi(char *str);
void    free_matrice(char **matrice);
void ft_exit(int i, t_map *map);
int ft_strlen_int(char *str);
int close_with_cross(t_map *map);
void ft_clear(t_map *map);
// int ft_strlen(char *str);

#endif


//1. parsing si map est arguement valides;
//2. implementer l'affichage des maps et sprites;
//3. deplacement du joueur et mise en places des animation;