/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 11:31:48 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/12 02:44:19 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <string.h>
# include <stdio.h>
# define FILLER_H
#include <errno.h>

typedef struct s_map		t_map;

struct	s_map
{
	char	*content;
	int		size;
	int		rows;
	int		cols;
};

enum	e_stream {STDIN, STDOUT, STDERR};
extern	int g_fderr;
void	get_player_number(char *line, int *player_num);
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
#endif