
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

    first_o = ft_strchr_casei(map->content, 'o');
    first_x = ft_strchr_casei(map->content, 'x');
    *first_o = (player == 1) ? -1 : 1;
    *first_x = (player == 2) ? -1 : 1;
    char *res;
    while ((res = ft_strchr(map->content, '.')))
        *res = 0;
}

void    ft_heatmap(t_map *map, t_map *token, int player)
{

    (void)token;
    init_map(map, player);
}