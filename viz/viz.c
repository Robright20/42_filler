/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 02:58:06 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/03 06:45:25 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viz.h"

int		main(int ac, char **av)
{
	static t_garb	g;
	t_env			*env;
	t_ivec2			win;
	char			*line;

	if (ac >= 2)
	{
		win.x = ft_atoi(av[1]);
		win.y = ft_atoi(av[2]);
		ft_setup(&env, &win, av[3], &g);
		line = NULL;
		get_next_line(STDIN, &line);
		mlx_string_put(env->ptr, env->win, 10, 10, 0x00ffffff, line);
		get_next_line(STDIN, &line);
		if (ft_strcmp(line, "cls") == 0)
		{
			//mlx_clear_window(env->ptr, env->win);
		}
		mlx_loop(env->ptr);
	}
	return (0);
}
