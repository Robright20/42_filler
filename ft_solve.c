/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <robright28@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:39:37 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/21 23:46:42 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_ivec2		g_pad;
int			g_player;

int		is_available(t_map *map, t_ivec3 *c_res, t_ivec3 *next_move)
{
	t_ivec2		offset;
	int			index;
	int			content;
	int			bool;

	offset.x = c_res->x + (next_move->x - g_pad.x);
	offset.y = c_res->y + (next_move->y - g_pad.y);
	bool = offset.x > 0 && offset.y > 0;
	if (bool && offset.x < map->cols && offset.y < map->rows)
	{
		index = offset.x + (offset.y * map->cols);
		content = map->content[index];
		if (content == '.')
			return (1);
		else if (content == g_player || content == ft_tolower(g_player))
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

int		check_position(t_ivec3 *c_pos, t_map *map, t_map *token)
{
	t_ivec3 n_star;
	int		ret;
	int		intersect;
	int		pad_state;

	intersect = 0;
	token->offset = 0;
	pad_state = 1;
	while (get_next_move(token, &n_star) == 1)
	{
		if (pad_state && !(pad_state = 0))
			g_pad = (t_ivec2){n_star.x, n_star.y};
		if ((ret = is_available(map, c_pos, &n_star)) >= 0)
		{
			intersect += (ret == 0);
			n_star.z = (map->offset - 1) + \
				(n_star.x + n_star.y * map->cols);
			c_pos->z += map->heatmap[n_star.z];
		}
		else
			break ;
	}
	return (ret >= 0 ? intersect == 1 : ret);
}

void	ft_pput(int fd, int n, int m)
{
	ft_putnbr_fd(n, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(m, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_solve(t_map *map, t_map *token, int player)
{
	t_ivec3 best_pos;
	t_ivec3 c_pos;
	int		ret;

	map->offset = 0;
	best_pos = (t_ivec3){0, 0, MAX_INT};
	g_player = player;
	while (get_next_move(map, &c_pos) == 1)
	{
		ret = check_position(&c_pos, map, token);
		if (ret > 0 && c_pos.z < best_pos.z)
		{
			best_pos.x = c_pos.x;
			best_pos.y = c_pos.y;
			best_pos.z = c_pos.z;
		}
	}
	ft_pput(STDOUT, best_pos.y - g_pad.y, best_pos.x - g_pad.x);
	ft_pput(STDERR, best_pos.y - g_pad.y, best_pos.x - g_pad.x);
}
