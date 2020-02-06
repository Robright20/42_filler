/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 02:58:06 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/07 00:09:28 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viz.h"

int		main(int ac, char **av)
{
	static t_garb	g;
	t_env			*env;
	t_ivec2			win;

	if (ac >= 2)
	{
		win.x = 800;
		win.y = 800;
		ft_setup(&env, &win, av, &g);
		mlx_loop_hook(env->ptr, ft_update, env);
		mlx_loop(env->ptr);
	}
	return (0);
}
