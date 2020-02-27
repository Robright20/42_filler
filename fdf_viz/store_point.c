/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:59:08 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/27 01:05:01 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_projection(t_point *p, int type)
{
	double x;

	if (type == 1)
	{
		x = p->x;
		p->x = (x - p->y) * cos(0.523599);
		p->y = (x + p->y) * sin(0.523599);
		p->x += 500;
	}
}

void	draw_map(t_map *map, t_win window, int projection)
{
	int		i;
	int		k;
	t_point	p1;
	t_point	p2;

	i = -1;
	k = 1;
	mlx_clear_window(window.mlx_ptr, window.win_ptr);
	ft_put_banner(&window, (t_filler*)map->more);
	while (++i < map->size)
	{
		p1 = map->tab[i];
		ft_projection(&p1, projection);
		if (i + 1 < map->width * k || !(k++))
		{
			p2 = map->tab[i + 1];
			ft_projection(&p2, projection);
			draw_line(window, p1, p2);
		}
		if (i + map->width < map->size)
		{
			p2 = map->tab[i + map->width];
			ft_projection(&p2, projection);
			draw_line(window, p1, p2);
		}
	}
}

void	store_point(char *s, t_map *map)
{
	char	*line;
	t_incr	incr;
	int		fd;
	double	scale;
	int		color;

	incr.k = -1;
	incr.j = 0;
	fd = open(s, O_RDONLY);
	map->tab = (t_point *)ft_memalloc((map->size + 1) * sizeof(t_point));
	scale = SCALE;
	while (get_next_line(fd, &line) > 0)
	{
		incr.i = -1;
		map->split = ft_strsplit(line, ' ');
		while (++incr.i < map->width)
		{
			color = ft_atoi(map->split[incr.i]);
			map->tab[++incr.k].x = incr.i * scale + TRANS_X;
			map->tab[incr.k].y = incr.j * scale + TRANS_Y;
			map->tab[incr.k].z = color * scale;
			if (color == 2)
				color = 0x00ff0000;
			else if (color == 4)
				color = 0x0000ff00;
			else
				color = 0x00ffffff;
			map->tab[incr.k].color = color;
		}
		incr.j++;
		free(line);
		ft_memdel2d(map->split);
	}
	close(fd);
}
