
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
        first_o = ft_strchr_casei(map->content, 'o');
        first_x = ft_strchr_casei(map->content, 'x');
        if (!first_o || !first_x)
            break ;
        *first_o = (player == 1) ? -1 : 1;
        *first_x = (player == 2) ? -1 : 1;
    }
}

void    place_closer(t_map *map, int index, int value)
{
    if ((index % map->cols) && map->content[index - 1] == '.')
        map->content[index - 1] = value;
    if ((index % map->cols < map->cols - 1) && map->content[index + 1] == '.')
        map->content[index + 1] = value;
    if (map->content[index] == '.')
        map->content[index] = value;
}

void    place_around(t_map *map, int index, int value)
{
    place_closer(map, index, value);
    if (index + map->cols < map->size)
        place_closer(map, index + map->cols, value);
    if (index - map->cols > 0)
        place_closer(map, index - map->cols, value);
}

void    ft_heatmap(t_map *map, t_map *token, int player)
{
    int     index;
    int     c;
    int     state;
    
    (void)token;
    init_map(map, player);
    c = 1;
    index = 0;
    state = 1;
    while (state)
    {
        state = 0;
        index = 0;
        while (index < map->size)
        {
            if (map->content[index] == c)
            {
                place_around(map, index, c + 1);
                state = 1;
            }
            index++;
        }
        c++;      
    }
}