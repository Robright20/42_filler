/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 11:32:35 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/11 02:18:58 by fokrober         ###   ########.fr       */
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

	fd = open("results", O_RDWR);
	if (fd < 0)
		exit(EXIT_FAILURE);
	ret = get_next_line(STDIN, &line);
	dprintf(fd, "%s\n", line);
	get_player_number(line, &player_num);
	free(line);

	ret = get_next_line(STDIN, &line);
	dprintf(fd, "%s\n", line);
	get_map(line, &map);
	dprintf(fd, "rows %d, cols %d\n", map.cols, map.rows);
	close(fd);
	return (0);
}
