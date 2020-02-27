/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <ielouazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:59:44 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/27 01:10:05 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_win window, t_point p1, t_point p2)
{
	double			dx;
	double			dy;
	double			max;
	t_point			incr;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (fabs(dx) > fabs(dy))
		max = fabs(dx);
	else
		max = fabs(dy);
	incr.x = dx / max;
	incr.y = dy / max;
	incr.z = 0;
	while (incr.z <= max)
	{
		mlx_pixel_put(window.mlx_ptr, window.win_ptr, round(p1.x), round(p1.y),
				p1.color);
		p1.x = incr.x + p1.x;
		p1.y = incr.y + p1.y;
		incr.z++;
	}
}
