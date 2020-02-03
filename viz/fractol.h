/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:18:35 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/03 05:36:16 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <sys/stat.h>
# include <OpenCL/opencl.h>
# include <math.h>
# include <string.h>
# define IMAGE_X 800
# define IMAGE_Y 800
# define WIN_X 1000
# define WIN_Y 1000
# define ITERATION 250
# define VECTOR_SIZE IMAGE_X * IMAGE_Y
# define IS_MANDELBROT (set.fractal == MANDELBROT)
# define IS_TRICORN (set.fractal == TRICORN)
# define IS_JULIA (set.fractal == JULIA)
# define TRACK_MOUSE (env->set->track_mouse)

typedef struct s_env	t_env;
typedef struct s_img	t_img;
typedef struct s_set	t_set;
typedef struct s_pixel	t_pixel;
typedef struct s_point	t_point;
typedef struct s_garb	t_garb;
typedef struct s_fvec2	t_fvec2;
typedef struct s_fvec4	t_fvec4;
typedef struct s_ivec4	t_ivec4;
typedef struct s_ivec2	t_ivec2;
typedef enum e_fractals	t_fractals;
typedef enum e_key		t_key;

struct			s_pixel
{
	int		x;
	int		y;
	size_t	color;
};
struct			s_point
{
	int		x;
	int		y;
	int		z;
	size_t	color;
};
struct			s_garb
{
	t_list	*images;
	int		env_count;
	void	*mlx_ptr;
};
struct			s_fvec2
{
	double	x;
	double	y;
};
struct			s_ivec2
{
	int		x;
	int		y;
};
struct			s_fvec4
{
	t_fvec2	v1;
	t_fvec2 v2;
};
struct			s_ivec4
{
	t_ivec2	v1;
	t_ivec2 v2;
};
struct			s_set
{
	int		fractal;
	t_fvec4	bounds;
	t_fvec2	c;
	int		track_mouse;
	int		iter;
	double	shift;
	int		color1;
	int		color2;
};
struct			s_env
{
	void	*ptr;
	void	*win;
	char	*title;
	t_ivec2	size;
	t_garb	*garb;
	t_img	*img;
};
struct			s_img
{
	void	*ptr;
	char	*data;
	int		bpp;
	int		line;
	int		endian;
	t_fvec4 bounds;
};
enum		e_fractals
{
	MANDELBROT = 1, JULIA, TRICORN
};
enum		e_key
{
	KEY_C = 8, KEY_I = 34, ESC = 53, PLUS = 69, MINUS = 78, KEY_R = 15,
	KEY_LEFT = 123, KEY_RIGHT, KEY_DOWN = 125, KEY_UP
};
enum		e_mouse_key
{
	MOUSE_LEFT = 1, MOUSE_RIGHT, SCROLL_DOWN = 4, SCROLL_UP
};
int				ft_imap(int nbr, t_ivec2 b1, t_ivec2 b2);
double			ft_fmap(double nbr, t_fvec2 b1, t_fvec2 b2);
void			ft_setup(t_env **env, t_ivec2 *win, char *title, t_garb *g);
void			ft_draw(t_img *img, t_set *set, t_env *env);
void			free_images(t_list *images);
void			set_pixel_img(t_img *img, int x, int y, int color);
int				ft_keypress(int keycode, void *params);
int				ft_mouse(int button, int x, int y, void *ptr);
int				ft_mouse_mv(int x, int y, void *params);
t_env			*ft_new_env(char *title, int width, int height, t_garb *g);
t_img			*ft_new_image(void *mlx_ptr, int width, int height, t_garb *g);
void			draw_line_img(t_img *img, t_point p1, t_point p2);
void			ft_border_img(t_img *img);
int				ft_exit(void *params);
#endif
