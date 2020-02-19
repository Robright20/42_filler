/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <robright28@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 11:32:35 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/19 01:09:55 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		g_fderr;

int		main(void)
{
	char	*line;
	int		player_num;
	int		ret;
	t_map 	map;
	t_map 	token;

	g_fderr = open("results", O_RDWR | O_CREAT);
	if (g_fderr < 0)
		exit(EXIT_FAILURE);
	ret = get_next_line(STDIN, &line);
	get_player_number(line, &player_num);
	free(line);

	ft_bzero(&map, sizeof(t_map));
	ft_bzero(&token, sizeof(t_map));

	ret = get_next_line(STDIN, &line);
	get_map_dim(line, &map);
	free(line);
	get_map_content(&map);

	get_next_line(STDIN, &line);
	get_token_dim(line , &token);
	free(line);
	f_get_token(&token);
	t_ivec2 next_move;
	token.offset = 0;
	while ((ret = get_next_move(&token, &next_move)) > 0)
	{
		//dprintf(g_fderr, "t_x %d\tt_y %d\n", next_move.x, next_move.y);
	}
	//ft_heatmap(&map, &token, player_num);
	token.offset = 0;
	map.offset = 0;
	ft_solve(&map, &token, -1);
	ft_putstr_map(&map, g_fderr);
	ft_putstr_map(&token, g_fderr);
	close(g_fderr);
	return (0);
}
