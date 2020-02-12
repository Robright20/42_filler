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

int		ft_isnumber(char *s)
{
	while (s && *s)
	{
		if (!ft_isdigit(*s++))
			return (0);
	}
	return (!!s);
}

int		count_tab(void *tab)
{
	int		i;

	i = 0;
	while (tab && *((void**)tab + i))
		i++;
	return (i);	
}

void	ft_memdel2d(void **mem)
{
	void	**tmp;

	if (mem)
	{
		tmp = mem;
		while (mem && *mem)
			free(mem++);
		free(tmp);
	}
}

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
	char	**tab;
	char	*c;
	int i;

	i = expect.size;
	c = ft_strchr(line, ':');
	if (c && ft_strncmp(expect.s, line, expect.size) == 0)
	{
		*c = '\0';
		tab = ft_strsplit(&line[expect.size], ' ');
		if (count_tab(tab) == 2 && ft_isnumber(tab[0]) && ft_isnumber(tab[1]))
		{
			dprintf(fd, "%s | %s\n", tab[0], tab[1]);
			map->rows = ft_atoi(tab[0]);
			map->cols = ft_atoi(tab[1]);
		}
		//ft_memdel2d((void**)tab);
	}
	if (map->rows == 0 || map->cols == 0) 
	{
		ft_putstr_fd("error map !\n", STDERR);
		exit(EXIT_FAILURE);
	}
}