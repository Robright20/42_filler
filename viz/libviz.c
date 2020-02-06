/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libviz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 00:09:08 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/07 00:09:19 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viz.h"

void	ft_background_color(t_img *img, int color)
{
	int		i;
	int		j;

	j = 0;
	while (j < img->size.y)
	{
		i = 0;
		while (i < img->size.x)
		{
			((int *)img->data)[i + j * img->size.x] = color;
			i++;
		}
		j++;
	}
}

void	ft_create_img(t_env *env, int color, t_ivec2 coords)
{
	t_img	*img;

	img = ft_new_image(env->ptr, 20, 20, env->garb);
	ft_background_color(img, color);
	ft_border_img(img, 0x00aaaaaa);
	mlx_put_image_to_window(env->ptr, env->win, img->ptr, \
			coords.x, coords.y);
}

void	ft_apply_buf(t_env *env, int img_pos)
{
	static int	color[] = {0x00000000, 0x000000ff,\
		0x0000000aa, 0x0000ff00, 0x0000aa00};
	int			i;
	int			pos;
	t_ivec2		coords;

	i = -1;
	coords.y = (env->imgs[img_pos])->size.y / 3;
	while ((env->imgs[img_pos])->buf[++i])
	{
		coords.x = (env->imgs[img_pos])->size.x / 3;
		while ((env->imgs[img_pos])->buf[i] != '\n')
		{
			if ((pos = ft_memichr(".oOxX", \
							(env->imgs[img_pos])->buf[i], 5)) >= 0)
				ft_create_img(env, color[pos], coords);
			coords.x += 20;
			i++;
		}
		coords.y += 20;
	}
}

void	fill_buffer(int fd, char **buf)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] != '\0')
		{
			*buf = ft_strcat(*buf, line);
			*buf = ft_strcat(*buf, "\n");
		}
		else
		{
			free(line);
			break ;
		}
		free(line);
	}
}

int		ft_update(t_env *env)
{
	static int	i;
	int			size;

	size = env->dim.x * env->dim.y + env->dim.x;
	if (i < env->maps_nb)
	{
		if (!(env->imgs[i]))
		{
			(env->imgs[i]) = ft_new_image(env->ptr, env->dim.y * 40, \
					env->dim.x * 40, env->garb);
			(env->imgs[i])->buf = ft_memalloc(size);
		}
		fill_buffer(env->log_file_fd, &((env->imgs[i])->buf));
		ft_apply_buf(env, i);
		free((env->imgs[i])->buf);
		usleep(500);
		i++;
	}
	return (0);
}
