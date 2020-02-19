/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <robright28@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:39:37 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/20 00:33:45 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_position(t_map *map, t_ivec2 *c_pos, t_ivec2 *next_move, int p)
{
	t_ivec2		offset;
	int			index;
	int			content;
	
	offset.x = c_pos->x + next_move->x;
	offset.y = c_pos->y + next_move->y;
	if (offset.x < map->cols && offset.y < map->rows)
	{
		index = offset.x + (offset.y * map->cols);
		content = map->content[index];
		if (content == '.')
			return (1);
		else if (content == p || content == ft_tolower(p))
			return (0);
	}
	return (-1);
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

void	ft_putstr_token(t_map *map, t_map *token, t_ivec2 *coords)
{
	int		offset;
	int		map_offset;
	t_ivec2	next_move;

	token->offset = 0;
	map_offset = coords->x + coords->y * map->cols;
	while (get_next_move(token, &next_move))
	{
		offset = map_offset + (next_move.x + next_move.y * map->cols);
		map->content[offset] = '*';
	}
}

void	ft_putnbr_token(t_map *map, t_map *token, t_ivec2 *coords)
{
	int		offset;
	int		map_offset;
	t_ivec2	next_move;

	token->offset = 0;
	map_offset = coords->x + coords->y * map->cols;
	while (get_next_move(token, &next_move))
	{
		offset = map_offset + (next_move.x + next_move.y * map->cols);
		map->heatmap[offset] =  '*';
	}
}

int    ft_solve(t_map *map, t_map *token, int player)
{
	t_ivec2 current_result;
	t_ivec2 best_result;
	t_ivec2 next_move;
	int		ret;
	int		c_player;
	int		offset;
	int		current_score;
	int		best_score;

	ret = 0;
	c_player = 0;
	map->offset = 0;
	token->offset = 0;
	best_score = 2147483647;
	best_result = (t_ivec2){0, 0};
	while (get_next_move(map, &current_result) > 0)
	{
		current_score = 0;
		c_player = 0;
		token->offset = 0;
		while ((ret = get_next_move(token, &next_move)) > 0)
		{
			if ((ret = check_position(map, &current_result, &next_move, player)) >= 0)
			{
				c_player += (ret == 0);
				if (ret ==  0)
					dprintf(g_fderr, "map (%d, %d)\ttok (%d, %d) : ret == %d;\n", current_result.x, current_result.y, \
							next_move.x, next_move.y, ret);
				offset = (map->offset - 1) + (next_move.x + next_move.y * map->cols);
				current_score += map->heatmap[offset];
			}
			else
				break ;
		}
		if ((ret >= 0) && (c_player == 1) && (current_score < best_score))
		{
			best_score = current_score;
			best_result.x = current_result.x;
			best_result.y = current_result.y;
			dprintf(g_fderr, "\t\t----- best_place = %d, %d;\n", best_result.y, best_result.x);
		}
	}
	// ft_putnbr_map(map, g_fderr);
	// free(map->content);
	// free(map->heatmap);
	//ft_putstr_token(map, token, &best_result);
	dprintf(g_fderr, "++%d\t%d\n", best_result.y, best_result.x);
	dprintf(STDOUT, "%d %d\n", best_result.y , best_result.x );
	if (best_result.y == 0 && best_result.y == 0 && best_score == 2147483647)
		return (0);
	else
		return (1);
	//dprintf(g_fderr, "%d %d\n", best_result.y , best_result.x );
	//ft_putstr_map(map, g_fderr);
}
