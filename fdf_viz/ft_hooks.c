/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <ielouazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:06:58 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/27 02:51:27 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	g_proj = 0;

int		rcv_key_events(int keycode, t_win *win)
{
	if (keycode == 53)
		ft_exit(win);
	if (keycode == 8)
	{
		g_proj = (g_proj == 0);
		draw_map(win->map, *win, g_proj);
	}
	return (0);
}

int		ft_exit(t_win *win)
{
	free(win->map->tab);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	close(((t_filler*)(win->map->more))->fd);
	exit(0);
	return (0);
}
