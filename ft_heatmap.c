/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <robright28@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 09:25:58 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/20 09:31:47 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char    *ft_strchr_casei(char *str, char c)
{
    char *res;

    if (!(res = ft_strchr(str, c)))
        return (ft_strchr(str, ft_toupper(c)));
    else
        return (res);
}    


void    init_map(t_map *map, int player)
{
    char    *first_o;
    char    *first_x;
    
    while(1)
    {
        first_o = ft_strchr_casei(map->heatmap, 'o');
        first_x = ft_strchr_casei(map->heatmap, 'x');
        if (!first_o && !first_x)
            break ;
        if (first_o)
            *first_o = (player == 1) ? -1 : 1;
        if (first_x)
            *first_x = (player == 2) ? -1 : 1;
    }
}

void    place_closer(t_map *map, int index, int value)
{
    if ((index % map->cols) && map->heatmap[index - 1] == '.')
        map->heatmap[index - 1] = value;
    if ((index % map->cols < map->cols - 1) && map->heatmap[index + 1] == '.')
        map->heatmap[index + 1] = value;
    if (map->heatmap[index] == '.')
        map->heatmap[index] = value;
}

void    place_around(t_map *map, int index, int value)
{
    place_closer(map, index, value);
    if (index + map->cols < map->size)
        place_closer(map, index + map->cols, value);
    if (index - map->cols > 0)
        place_closer(map, index - map->cols, value);
}

void    ft_heatmap(t_map *map, int player)
{
    int     index;
    int     c;
    int     state;
    
    map->heatmap = ft_strdup(map->content);
    init_map(map, player);
    c = 1;
    state = 1;
    while (state)
    {
        state = 0;
        index = 0;
        while (index < map->size)
        {
            if (map->heatmap[index] == c)
            {
                place_around(map, index, c + 1);
                state = 1;
            }
            index++;
        }
        c++;      
    }
}
