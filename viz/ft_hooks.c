/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 20:29:23 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/03 05:36:30 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_images(t_list *images)
{
	t_list *tmp;

	while (images)
	{
		free(images->content);
		tmp = images->next;
		free(images);
		images = tmp;
	}
}

int		ft_exit(void *params)
{
	t_env	*env;

	env = (t_env *)params;
	mlx_destroy_window(env->ptr, env->win);
	if (!(--env->garb->env_count))
	{
		free_images(env->garb->images);
		free(params);
		exit(0);
	}
	free(params);
	return (0);
}

int		ft_echap(int keycode, void *params)
{
	if (keycode == ESC)
		ft_exit(params);
	return (0);
}
