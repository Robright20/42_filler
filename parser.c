/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:59:28 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/11 02:24:50 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
int	fd;
void	get_player_number(char *line, int *player_num)
{
	static t_string expect = (t_string){"$$$ exec p", 10};
	
	if (ft_strncmp(expect.s, line, expect.size) != 0)
	{
		ft_putstr_fd("error player number !\n", STDERR);
		exit(EXIT_FAILURE);
	}
	else
		*player_num = ft_atoi(&line[expect.size]); 
}

void	get_map(char *line, t_map *map)
{
	static t_string expect = (t_string){"Plateau ", 8};
	int i;

	i = expect.size;
	if (ft_strncmp(expect.s, line, expect.size) != 0)
	{
		ft_putstr_fd("error map !\n", STDERR);
		exit(EXIT_FAILURE);
	}
	else
	{
		map->rows = ft_atoi(&line[expect.size]);
		while (line[i])
			if (line[i++] == ' ')
				break ;
		map->cols = ft_atoi(&line[i]);
		if (map->rows == 0 || map->cols == 0)
		{	
			ft_putstr_fd("error map !\n", fd);
			exit(EXIT_FAILURE);
		}
	}
}
