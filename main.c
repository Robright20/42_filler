/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 11:32:35 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/12 23:08:01 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fd;

int		main(void)
{
	char	*line;
	int		player_num;
	int		ret;
	t_map 	map;
	
	fd = open("results", O_RDWR | O_CREAT);
	if (fd < 0)
		exit(EXIT_FAILURE);
	ret = get_next_line(STDIN, &line);
	get_player_number(line, &player_num);
	free(line);

	ft_bzero(&map, sizeof(t_map));

	ret = get_next_line(STDIN, &line);
	get_map_dim(line, &map);
	free(line);
	get_map_content(STDIN, &map);
	close (fd);
	return (0);
}
