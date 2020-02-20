/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <robright28@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 09:57:21 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/20 09:57:41 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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