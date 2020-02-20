/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <robright28@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:39:37 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/20 12:58:37 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_position(t_map *map, t_ivec3 *c_res, t_ivec3 *next_move, int p)
{
	t_ivec2		offset;
	int			index;
	int			content;
	
	offset.x = c_res->x + next_move->x;
	offset.y = c_res->y + next_move->y;
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

int		get_next_move(t_map *map, t_ivec3 *next_move)
{
	while (map->content[map->offset])
	{
		if (ft_strchr(map->charset, map->content[map->offset]))
		{
			next_move->x = map->offset % map->cols;
			next_move->y = map->offset / map->cols;
			next_move->z = 0;
			map->offset++;
			return (1);
		}
		map->offset++;
	}
	return (0);
}

int    ft_solve(t_map *map, t_map *token, int player)
{
	t_ivec3 best_pos;
	t_ivec3 c_pos;
	t_ivec3 n_star;
	int		ret;
	int		p_sub;

	map->offset = 0;
	best_pos = (t_ivec3){0, 0, MAX_INT};
	while (get_next_move(map, &c_pos) > 0)
	{
		token->offset = 0;
		p_sub = 0;
		while (get_next_move(token, &n_star) > 0)
		{
			if ((ret = check_position(map, &c_pos, &n_star, player)) >= 0)
			{
				p_sub += (ret == 0);
				n_star.z = (map->offset - 1) + (n_star.x + n_star.y * map->cols);
				c_pos.z += map->heatmap[n_star.z];
			}
			else
				break ;
		}
		if ((ret >= 0) && (p_sub == 1) && (c_pos.z < best_pos.z))
		{
			best_pos.x = c_pos.x;
			best_pos.y = c_pos.y;
			best_pos.z = c_pos.z;
		}
	}
	dprintf(STDOUT, "%d %d\n", best_pos.y , best_pos.x);
	return (1);
}
