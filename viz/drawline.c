/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 00:53:53 by fokrober          #+#    #+#             */
/*   Updated: 2020/01/23 15:31:21 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	x_sampling(t_img *img, t_point p1, int *draw)
{
	int		p;
	t_point	pt;
	int		i;

	pt = p1;
	p = draw[0] / 2;
	i = -1;
	while (++i < draw[0])
	{
		pt.x += draw[2];
		p += draw[1];
		if (p > draw[0])
		{
			p -= draw[0];
			pt.y += draw[3];
		}
		set_pixel_img(img, pt.x, pt.y, pt.color);
	}
	set_pixel_img(img, p1.x, p1.y, p1.color);
}

void	y_sampling(t_img *img, t_point p1, int *draw)
{
	int		p;
	t_point pt;
	int		i;

	i = -1;
	pt = p1;
	p = draw[1] / 2;
	while (++i < draw[1])
	{
		pt.y += draw[3];
		p += draw[0];
		if (p > draw[1])
		{
			p -= draw[1];
			pt.x += draw[2];
		}
		set_pixel_img(img, pt.x, pt.y, pt.color);
	}
	set_pixel_img(img, p1.x, p1.y, p1.color);
}

void	draw_line_img(t_img *img, t_point p1, t_point p2)
{
	int		draw[4];

	draw[0] = abs(p2.x - p1.x);
	draw[1] = abs(p2.y - p1.y);
	draw[2] = (p1.x < p2.x) ? 1 : -1;
	draw[3] = (p1.y < p2.y) ? 1 : -1;
	if (draw[0] > draw[1])
		x_sampling(img, p1, draw);
	else
		y_sampling(img, p1, draw);
}
