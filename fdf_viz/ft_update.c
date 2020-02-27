/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:05:31 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/27 02:45:55 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		g_score[2] = {0, 0};

int		ft_update(t_win *win)
{
	t_map		*map;
	t_filler	*game;
	static int	i;

	map = win->map;
	game = (t_filler*)map->more;
	if (i == 0)
	{
		draw_map(win->map, *win, 0);
		i = 1;
	}
	else if (game->moves)
	{
		draw_move(win, game->moves->content, g_proj);
		if (((t_move*)game->moves->content)->pid == 'X')
			g_score[0]++;
		else if (((t_move*)game->moves->content)->pid == 'O')
			g_score[1]++;
		game->moves = game->moves->next;
	}
	usleep(500);
	return (0);
}

void	ft_put_banner(t_win *win, t_filler *game)
{
	if (game)
	{
		mlx_string_put(win->mlx_ptr, win->win_ptr, 260, 40, \
				game->p[0][0] == 'X' ? 0x0000ff00 : 0x00ff0000, game->p[0]);
		mlx_string_put(win->mlx_ptr, win->win_ptr, 310, 80, \
				game->p[0][0] == 'X' ? 0x0000ff00 : 0x00ff0000, ft_itoa(g_score[0]));
		mlx_string_put(win->mlx_ptr, win->win_ptr, 560, 40, \
				game->p[1][0] == 'O' ? 0x00ff0000 : 0x0000ff00, game->p[1]);
		mlx_string_put(win->mlx_ptr, win->win_ptr, 610, 80, \
				game->p[1][0] == 'O' ? 0x00ff0000 : 0x0000ff00, ft_itoa(g_score[1]));
	}
}
