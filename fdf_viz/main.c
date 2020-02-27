/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <ielouazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:55:17 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/26 13:43:29 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_win window;
	t_map map;

	if (ac == 2)
	{
		get_map_info(av[1], &map);
		window.mlx_ptr = mlx_init();
		window.win_ptr = mlx_new_window(window.mlx_ptr, WIN_X, WIN_Y, "hell");
		window.map = &map;
		store_point(av[1], &map);
		draw_map(&map, window, 0);
		filler_setup(&map);
		mlx_key_hook(window.win_ptr, rcv_key_events, &window);
		mlx_hook(window.win_ptr, 17, 0, ft_exit, &window);
		mlx_loop_hook(window.mlx_ptr, ft_update, &window);
		mlx_loop(window.mlx_ptr);
	}
	else
	{
		ft_putstr("Usage : ");
		ft_putstr(av[0]);
		ft_putendl(" <filename> [ case_size z_size ]");
	}
	return (0);
}
