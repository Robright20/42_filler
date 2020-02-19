/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <robright28@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 11:31:48 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/20 00:22:53 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <string.h>
# include <stdarg.h>
# include <stdio.h>
# define FILLER_H
# define MAP_CHARSET ".xXoO"
# define TOKEN_CHARSET "*"
#include <errno.h>

typedef struct s_map		t_map;
typedef struct s_ivec2		t_ivec2;

struct	s_map
{
	char		*content;
	int			size;
	int			rows;
	int			cols;
	int			offset;
	const char	*charset;
	char		*heatmap;
};

struct	s_ivec2
{
	int x;
	int y;
};

enum	e_stream {STDIN, STDOUT, STDERR};
extern	int g_fderr;
void	get_player_number(char *line, int *p_num, char *p_name);
void	ft_putdstr(int fd, char *s);
void	get_map_dim(char *line, t_map *map);
void	get_map_content(t_map *map);
void	f_get_token(t_map *token);
int		ft_isnumber(char *s);
int		ft_validline(int cols, char *line);
int		ft_tab2dlen(void *tab);
void	ft_memdel2d(void **mem);
void	ft_putstr_map(t_map *map, int stream);
void	ft_putnbr_map(t_map *map, int stream);
void	get_token_dim(char *line, t_map *token);
void    ft_heatmap(t_map *map, t_map *token, int player);
int		ft_solve(t_map *map, t_map *token, int player);
int		get_next_move(t_map *map, t_ivec2 *next_move);
int     ft_sprintf(char *restrict str, const char *fmt, ...);
#endif
