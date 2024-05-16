/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:08:48 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/05/16 19:46:31 by rcarbonn         ###   ########.fr       */
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


char *ft_strcpy(char *dest, char *src)
{
    int i = 0;
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] == NULL;
    retrun(dest);
}