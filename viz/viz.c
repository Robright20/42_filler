/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 02:58:06 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/03 08:50:51 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viz.h"

int		ft_update(void *param)
{
	t_env	*env;
	char	*line;
	static	int	i;

	env = (t_env *)param;
	line = NULL;
	if (get_next_line(STDIN, &line) > 0)
	{
		if (ft_strcmp(line, "cls") == 0)
		{
			i = 0;
			mlx_clear_window(env->ptr, env->win);
		}
		else
		{
			mlx_string_put(env->ptr, env->win, 140, i + 10, 0x00ffffff, line);
			i += 20;
		}
		free(line);
	}
	return (0);
}

int		main(int ac, char **av)
{
	static t_garb	g;
	t_env			*env;
	t_ivec2			win;

	if (ac >= 2)
	{
		win.x = ft_atoi(av[1]);
		win.y = ft_atoi(av[2]);
		ft_setup(&env, &win, av[3], &g);
		mlx_loop_hook(env->ptr, ft_update, env);
		mlx_loop(env->ptr);
	}
	return (0);
}
