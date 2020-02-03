/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 03:55:27 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/03 05:41:34 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		clamp(int val, float v_min, int v_max)
{
	if (val == v_max)
		val = v_min;
	return (fmax(v_min, fmin(v_max, val)));
}


int		ft_keypress(int keycode, void *params)
{
	t_env	*env;

	env = (t_env *)params;
	(void)keycode;
	return (0);
}
