/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <robright28@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:39:37 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/19 02:18:37 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_position(t_map *map, t_ivec2 *c_pos, t_ivec2 *next_move, int player)
{
	t_ivec2		offset;
	int			index;
	//static	int	player_state;
	//static	int	previous_star;
	//if (map->content[index] == 'O')
	//	return (1);
	//else if (player_state && map->content[index])
	offset.x = c_pos->x + next_move->x;
	offset.y = c_pos->y + next_move->y;
	if (offset.x < map->cols && offset.y < map->rows)
	{
		index = offset.x + (offset.y * map->cols);
		if (map->content[index] == '.')
			return (1);
		else if (map->content[index] == player)
			return (0);
	}
	return (-1);
	//if player_state == 0 thats means no player piece wher found
	//and thats an error (return -1)
	//if we met a previous_star before? get the next one and if none (return 0)
	// if want to place a star and by checking the state of the previous (player_state met)
}

int		get_next_move(t_map *map, t_ivec2 *next_move)
{
	while (map->content[map->offset])
	{
		if (ft_strchr(map->charset, map->content[map->offset]))
		{
			*next_move = (t_ivec2){map->offset % map->cols,\
				map->offset / map->cols};
			map->offset++;
			return (1);
		}
		map->offset++;
	}
	return (0);
}

void    ft_solve(t_map *map, t_map *token, int player)
{
	char	*cpy;
	t_ivec2 current_result;
	t_ivec2 next_move;
	int		ret;
	int		c_player;
	int		offset;

	ret = 0;
	cpy = ft_memdup(map->content, map->size);
	c_player = 0;
	(void)player;
	while (get_next_move(map, &current_result) > 0)
	{
		//dprintf(g_fderr,"%d\t%d\t%d\n", current_result.x, current_result.y, map->offset);
		while ((ret = get_next_move(token, &next_move)) > 0)
		{
			if ((ret = check_position(map, &current_result, &next_move, 'X')) >= 0)
			{
				c_player += (ret == 0);
				offset = (map->offset - 1) + (next_move.x + next_move.y * map->cols);
				map->content[offset] = '*';
			}
			else
				break ;
		}
		if (ret < 0 || c_player != 1)
		{
			token->offset = 0;
			ft_memcpy(map->content, cpy, map->size);
		}
		else
			break ;
	}
}