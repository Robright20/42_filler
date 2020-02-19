/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <robright28@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 11:32:35 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/20 00:22:30 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		g_fderr;

int		main(int ac, char **av)
{
	char	*line;
	int		player_num;
	int		ret;
	t_map 	map;
	t_map 	token;

	g_fderr = open("results", O_RDWR | O_CREAT);
	if (g_fderr < 0)
		exit(EXIT_FAILURE);
	player_num = 0;
	if (player_num == 0)
	{
		ret = get_next_line(STDIN, &line);
		get_player_number(line, &player_num, av[0]);
		//ft_putstr_fd(line, g_fderr);
		free(line);
	}
	while (1)
	{
		ft_bzero(&map, sizeof(t_map));
		ft_bzero(&token, sizeof(t_map));
		ret = get_next_line(STDIN, &line);
		// ft_putstr_fd(line, g_fderr);
		get_map_dim(line, &map);
		free(line);
		get_map_content(&map);
		get_next_line(STDIN, &line);
		get_token_dim(line , &token);
		free(line);
		
		f_get_token(&token);
		ft_heatmap(&map, &token, player_num);
		if (0 == ft_solve(&map, &token, 'O'))
			break;
		ft_putnbr_map(&map, g_fderr);
		//ft_putstr_map(&token, g_fderr);
	}
	(void)ac;
	close(g_fderr);
	return (0);
}
