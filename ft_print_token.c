/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <robright28@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 09:57:21 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/21 22:25:21 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_putstr_token(t_map *map, t_map *token, t_ivec3 *coords)
{
	int		offset;
	int		map_offset;
	t_ivec3	next_move;

	token->offset = 0;
	map_offset = coords->x + coords->y * map->cols;
	while (get_next_move(token, &next_move))
	{
		offset = map_offset + (next_move.x + next_move.y * map->cols);
		map->content[offset] = '*';
	}
}

void	ft_putnbr_token(t_map *map, t_map *token, t_ivec3 *coords)
{
	int		offset;
	int		map_offset;
	t_ivec3	next_move;

	token->offset = 0;
	map_offset = coords->x + coords->y * map->cols;
	while (get_next_move(token, &next_move))
	{
		offset = map_offset + (next_move.x + next_move.y * map->cols);
		map->heatmap[offset] = '*';
	}
}

void	ft_putstr_map(t_map *map, int stream)
{
	int		k;

	k = 0;
	while (k < map->size)
	{
		dprintf(stream, "[%.*s]\n", map->cols, &(map->content[k]));
		k += map->cols;
	}
}

void	ft_putnbr_map(t_map *map, int stream)
{
	int		k;
	int		i;

	k = 0;
	while (k < map->size)
	{
		i = -1;
		while (++i < map->cols)
		{
			dprintf(stream, "%3d", map->heatmap[k]);
			k++;
		}
		ft_putstr_fd("\n", stream);
	}
}

int		ft_tab2dlen(void *tab)
{
	int		i;

	i = 0;
	while (tab && *((void**)tab + i))
		i++;
	return (i);
}
