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
	int		i;
	
	fd = open("results", O_RDWR | O_CREAT);
	if (fd < 0)
		exit(EXIT_FAILURE);
	ret = get_next_line(STDIN, &line);
	dprintf(fd, "%s\n", line);
	get_player_number(line, &player_num);
	

	ret = get_next_line(STDIN, &line);
	dprintf(fd, "%s\n", line);
	get_map(line, &map);
	dprintf(fd, "rows %d, cols %d\n", map.cols, map.rows);
	ret = get_next_line(STDIN, &line);
	i = 0;
	while (i < 4)
	{
		if (line[i++] != ' ')
			break ;
	}
	if (i != 4)
		exit(EXIT_FAILURE);
	while (1)
	{
		i = 0;
		while (i < 3)
		{
			if (!ft_isdigit(line[i]))
				break ;
		}
		if (i != 3 || line[4] != ' ')
			exit(EXIT_FAILURE);
		free(line);
		ret = get_next_line(STDIN, &line);
	}
	free(line);
	close (fd);
	return (0);
}
