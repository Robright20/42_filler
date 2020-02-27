/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <ielouazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:57:12 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/26 16:48:20 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define TRUE 1
# define FALSE 0
# define WIN_X 1000
# define WIN_Y 1000
# include "../libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# define TRANS_X (WIN_X / 2 - (map->width * scale) / 2)
# define TRANS_Y (WIN_Y / 2 - (map->len * scale) / 2)
# define SCALE (500 / map->width)

typedef	struct s_win	t_win;
typedef struct s_point	t_point;
typedef	struct s_map	t_map;
typedef struct s_incr	t_incr;
typedef	struct s_filler t_filler;
typedef	struct s_move	t_move;
typedef	struct s_ivec2	t_ivec2;

struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
};

struct	s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
};

struct	s_incr
{
	int	i;
	int	j;
	int	k;
};

struct	s_ivec2
{
	int	x;
	int	y;
};

struct	s_map
{
	int		size;
	int		len;
	int		width;
	t_point	*tab;
	int		current_width;
	char	**split;
	void	*more;
};

struct	s_filler
{
	t_map	*map;
	int		fd;
	char	*p[2];
	t_ivec2	dim;
	t_list	*moves;
};

struct	s_move
{
	t_point	*tab;
	int		nbstar;
	int		pid;
	t_ivec2	coords;
};

extern	int g_proj;
void	draw_line(t_win window, t_point p1, t_point p2);
void	store_point(char *s, t_map *map);
void	draw_map(t_map *map, t_win window, int projection);
void	get_map_info(char *s, t_map *map);
void	ft_memdel2d(char **ptr);
int		rcv_key_events(int keycode, t_win *window);
int		ft_exit(t_win *window);
void	filler_setup(t_map *map);
int		ft_update(t_win *win);
void	ft_put_banner(t_win *win, t_filler *game);
void	draw_move(t_win *win, t_move *mv);
#endif
