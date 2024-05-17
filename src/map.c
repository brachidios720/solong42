/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:56:40 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/17 17:47:02 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../gnl/get_next_line.h"

int line(char *file)
{
    int count_line;
    int fd;
    int read_line;
    char stock;

    fd = open(file, O_RDONLY);
    if(!fd)
        return(-1);
    count_line = 1;
    while(1)
    {
        read_line = read(fd, &stock, 1);
        if(read_line == 0)
            break;
        if(read_line < 0)
            return(-1);
        if(stock == '\n')
            count_line++;
    }
    close(fd);
    return(count_line);
}

char **map_alock(char *file)
{
    char **map;
    int ligne_count;

    ligne_count = line(file);
    if(ligne_count < 0)
        return(NULL);
    map = (char **)malloc(sizeof(char *) * (ligne_count + 1));
    if(!map)
    {
        ft_putstr("alloc failed");
        return(0);
    }
    return(map);
}

char **finish_map(char *file)
{
    char **map;
    int i = 0;
    int fd;
    
    
    map = map_alock(file);
    if(map == NULL)
        return(NULL);
    fd = open(file, O_RDONLY);
    if(fd < 0)
    {
        free(map);
        return(NULL);
    }
    while((map[i] = get_next_line(fd)) != NULL)
        i++;
    map[i] = NULL;
    close(fd);
    return(map);   
} 


// int main(void)
// {
//     char *map_file = "../map/map1.ber";
//     char **tab = finish_map(map_file);
//     int i = 0;

//     if (tab == NULL)
//         ft_putstr("Failed");
//     while (tab[i])
//     {
//         printf("%s", tab[i]);
//         free(tab[i]);
//         i++;
//     }
    
//     free(tab);
//     return (0);
// }

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
    t_map *dat = NULL;
    if(ac < 2)
    {
        return(0);
    }
    inis_map(dat, av);
	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    add_image(dat);
    parcours_map(dat);
	mlx_loop(mlx);
}