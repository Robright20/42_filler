/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <robright28@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:59:28 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/20 09:49:20 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	fderr;

int		ft_isnumber(char *s)
{
	while (s && *s)
	{
		if (!ft_isdigit(*s++))
			return (0);
	}
	return (!!s);
}

int		ft_tab2dlen(void *tab)
{
	int		i;

	i = 0;
	while (tab && *((void**)tab + i))
		i++;
	return (i);	
}

void	ft_memdel2d(void **mem)
{
	int		i;

	i = 0;
	if (mem)
	{
		while (mem[i])
			free(mem[i++]);
		free(mem);
	}
}

void	ft_putstr_map(t_map *map, int stream)
{
	int		k;

	k = 0;
	while (k < map->size)
	{
		dprintf(stream, "[%.*s]\n", map->cols, &(map->content[k]));
		k += map->cols;
	}
}

void	ft_putnbr_map(t_map *map, int stream)
{
	int		k;
	int		i;

	k = 0;
	while (k < map->size)
	{
		i = -1;
		while (++i < map->cols)
		{
			dprintf(stream, "%3d", map->heatmap[k]);
			k++;
		}
		ft_putstr_fd("\n", stream);
	}
}

void	get_player_number(char *line, int *player_num, char *pname)
{
	static t_string expect = (t_string){"$$$ exec p", 10};
	char			*s;
	char			*str;
	
	s = ft_strnew(ft_strlen(pname) + 2);
	ft_sprintf(s, "[%s]", pname);
	str = ft_strchr(line, '[');
	if (ft_strncmp(expect.s, line, expect.size) != 0 || !ft_strequ(str, s))
	{
		ft_putstr_fd("error player number !\n", STDERR);
		free(s);
		exit(EXIT_FAILURE);
	}
	else
		*player_num = ft_atoi(&line[expect.size]);
	free(s);
}

int		ft_validline(int cols, char *line)
{
	while (*line)
	{
		if (!(*line == '.' || *line == 'x' || *line == 'X' \
					|| *line == 'o' || *line == 'O'))
			return (0);
		line++;
	}
	return (cols == (int)ft_strlen(line));
}

void	get_map_content(t_map *map)
{
	char	*s;
	char	*line;
	int		i;

	if (get_next_line(STDIN, &line) <= 0)
		exit(EXIT_FAILURE);
	s = ft_strtrim(line);
	i = map->rows;
	if (map->cols == (int)ft_strlen(s) && ft_isnumber(s))
	{
		free(s);
		free(line);
		map->content = (char*)ft_memalloc(map->rows * map->cols + 1);
		map->charset = MAP_CHARSET;
		while (i-- && get_next_line(STDIN, &line) > 0 && (int)ft_strlen(line) > map->cols)
		{
			line[3] = '\0';
			if (!(ft_isnumber(line) || !ft_validline(map->cols, &line[4])))
				exit(EXIT_FAILURE);
			ft_strcat(map->content, &line[4]);
			free(line);
		}
	}
	else
		exit(EXIT_FAILURE);
}

void	get_map_dim(char *line, t_map *map)
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
		if (ft_tab2dlen(tab) == 2 && ft_isnumber(tab[0]) && ft_isnumber(tab[1]))
		{
			map->rows = ft_atoi(tab[0]);
			map->cols = ft_atoi(tab[1]);
			map->size = map->rows * map->cols;
			ft_memdel2d((void**)tab);
		}
	}
	if (map->rows == 0 || map->cols == 0) 
	{
		ft_putstr_fd("error map !\n", STDERR);
		exit(EXIT_FAILURE);
	}
}
