/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:08:52 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/15 15:34:58 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef so_long
#define so_long

#include<unistd.h>
#include<stdlib.h>

// strcut 

typedef struct s_map
{
    char **file;
    char *sprite_collectible;
    char *sprite_palyer;
    char *sprite_exit;
    char *sprite_wall;
    int   count_step;
    
} t_map;



// Utils

void ft_putstr(char *str);
int ft_atoi(char *str);

#endif


//1. parsing si map est arguement valides;
//2. implementer l'affichage des maps et sprites;
//3. deplacement du joueur et mise en places des animation;