/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 11:31:48 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/10 21:39:47 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <string.h>
# include <stdio.h>
# define FILLER_H
#include <errno.h>

typedef enum e_std_stream	t_std_stream;
typedef struct s_map		t_map;

struct	s_map
{
	char	*content;
	int		size;
	int		rows;
	int		cols;
};

enum	e_std_stream {STDIN, STDOUT, STDERR};
void	get_player_number(char *line, int *player_num);
void	ft_putdstr(int fd, char *s);
void	get_map(char *line, t_map *map);
#endif
