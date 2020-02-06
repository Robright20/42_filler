/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 03:54:08 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/07 00:07:49 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interp(double start, double end, double interpol)
{
	return (start + ((end - start) * interpol));
}

int		ft_mouse_mv(int x, int y, void *params)
{
	t_env	*env;

	env = (t_env *)params;
	(void)(x && y);
	return (0);
}

int		ft_mouse(int button, int x, int y, void *params)
{
	t_env	*env;

	env = (t_env *)params;
	(void)(button || (x && y));
	return (0);
}
