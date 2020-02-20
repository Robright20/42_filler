/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <robright28@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 11:32:35 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/20 12:58:43 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_setup(t_map *map, t_map *token, int *player_num)
{
	char	*line;

	ft_bzero(map, sizeof(t_map));
	ft_bzero(token, sizeof(t_map));
	if (get_next_line(STDIN, &line) <= 0)
		exit(EXIT_FAILURE);
	get_map_dim(line, map);
	free(line);
	get_map_content(map);
	if (get_next_line(STDIN, &line) <= 0)
		exit(EXIT_FAILURE);
	get_token_dim(line, token);
	free(line);
	f_get_token(token);
	ft_heatmap(map, *player_num);
}

int		main(int ac, char **av)
{
	char	*line;
	int		player_num;
	t_map	map;
	t_map	token;

	player_num = 0;
	if (player_num == 0)
	{
		if (get_next_line(STDIN, &line) <= 0)
			exit(EXIT_FAILURE);
		get_player_number(line, &player_num, av[0]);
		free(line);
	}
	while (ac)
	{
		ft_setup(&map, &token, &player_num);
		ft_solve(&map, &token, (player_num == 1 ? 'O' : 'X'));
		free(map.content);
		free(map.heatmap);
	}
	return (0);
}
