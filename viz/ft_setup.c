/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:52:51 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/03 05:44:58 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img	*ft_new_image(void *mlx_ptr, int width, int height, t_garb *g)
{
	t_img	*img;
	t_list	*tmp;

	img = (t_img*)malloc(sizeof(t_img));
	tmp = ft_lstnew(NULL, 0);
	tmp->content = img;
	tmp->content_size = sizeof(img);
	ft_lstpush2(&g->images, tmp);
	img->ptr = mlx_new_image(mlx_ptr, width, height);
	img->data = mlx_get_data_addr(img->ptr, &img->bpp, &img->line,
			&img->endian);
	img->bounds.v1 = (t_fvec2){0, width};
	img->bounds.v2 = (t_fvec2){0, height};
	return (img);
}

t_env	*ft_new_env(char *title, int width, int height, t_garb *g)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (g->env_count == 0)
		g->mlx_ptr = mlx_init();
	env->ptr = g->mlx_ptr;
	g->env_count++;
	env->garb = g;
	env->title = title;
	env->size = (t_ivec2){width, height};
	env->win = mlx_new_window(env->ptr, width, height, title);
	mlx_hook(env->win, 17, 0, ft_exit, env);
	mlx_hook(env->win, 2, 0, ft_keypress, env);
	mlx_hook(env->win, 4, 0, ft_mouse, env);
	mlx_hook(env->win, 6, 0, ft_mouse_mv, env);
	return (env);
}

void	ft_border_img(t_img *img)
{
	t_point		p0;
	t_point		p1;
	t_point		p2;
	t_point		p3;

	p0 = (t_point){0, 0, 0, 0xffffff};
	p1 = (t_point){IMAGE_X - 1, 0, 0, 0xffffff};
	p2 = (t_point){0, IMAGE_Y - 1, 0, 0xffffff};
	p3 = (t_point){IMAGE_X - 1, IMAGE_Y - 1, 0, 0xffffff};
	draw_line_img(img, p0, p1);
	draw_line_img(img, p0, p2);
	draw_line_img(img, p2, p3);
	draw_line_img(img, p1, p3);
}

void	ft_setup(t_env **env, t_ivec2 *win, char *title, t_garb *g)
{
	*env = ft_new_env(title, win->x, win->y, g);
}

void	set_pixel_img(t_img *img, int x, int y, int color)
{
	((int *)img->data)[x + y * (img->line / 4)] = color;
}
