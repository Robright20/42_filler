/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:59:08 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/27 06:34:30 by fokrober         ###   ########.fr       */
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
	int		alt;

	incr.k = -1;
	incr.j = 0;
	fd = open(s, O_RDONLY);
	map->tab = (t_point *)ft_memalloc((map->size + 1) * sizeof(t_point));
	while (get_next_line(fd, &line) > 0)
	{
		incr.i = -1;
		map->split = ft_strsplit(line, ' ');
		while (++incr.i < map->width)
		{
			alt = ft_atoi(map->split[incr.i]);
			map->tab[++incr.k] = (t_point){incr.i * SCALE + TRANS_X, \
				incr.j * SCALE + TRANS_Y, alt * SCALE, \
			(alt == 2) ? RED : (alt == 4) * GREEN + (alt != 4) * WHITE};
		}
		incr.j++;
		free(line);
		ft_memdel2d(map->split);
	}
	close(fd);
}
