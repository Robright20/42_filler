/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 11:32:35 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/04 09:14:39 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	char	*line;
	int		fd;
	char	**tab;
	int		size;

	line = NULL;
	tab = NULL;
	fd = open("filler.h", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		size = 0;
		while (tab && tab[size])
			size++;
		tab = (char **)ft_realloc(tab, (size + 1) * sizeof(char*), (size + 2) * sizeof(char*));
		tab[size] = line;
		tab[size + 1] = NULL;
	}
	size = 0;
	while (tab[size])
	{
		ft_putendl(tab[size]);
		free(tab[size]);
		size++;
	}
	free(tab);
	tab = NULL;
	line = NULL;
	close(fd);
	return (0);
}
