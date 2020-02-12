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
	// int		i;
	// int 	jumper;
	
	fd = open("results", O_RDWR | O_CREAT);
	if (fd < 0)
		exit(EXIT_FAILURE);
	ret = get_next_line(STDIN, &line);
	dprintf(fd, "%s\n", line);				
	get_player_number(line, &player_num);	// Player numer  
	

	ret = get_next_line(STDIN, &line);
	dprintf(fd, "%s\n", line);	 		// X / Y the coordinates (cols/rows)
	ft_bzero(&map, sizeof(t_map));
	get_map(line, &map);

	// while (jumper-- > 0 && ret == 1)
	// {
	// 	ret = get_next_line (STDIN, &line);
	// 	dprintf (fd, "%s\n", line); 		// printing the map update, line by line!
	// }

	free(line);
	close (fd);
	return (0);
}
