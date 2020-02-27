/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 05:43:38 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/27 05:51:17 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "tools.h"

t_filler	*filler_init(void)
{
	t_filler	*new;
	int			i;
	int			ret;
	char		**split;
	char		*line;

	if (!(new = (t_filler*)ft_memalloc(sizeof(t_filler))))
		return (NULL);
	new->fd = open("./filler.data", O_RDONLY);
	i = 2;
	while (i-- && (ret = get_next_line(new->fd, &line)) > 0)
	{
		line[0] = (line[0] == '1') ? 'O' : 'X';
		new->p[i] = line;
	}
	if (ret > 0 && (ret = get_next_line(new->fd, &line)) > 0)
	{
		split = ft_strsplit(line, ' ');
		free(line);
		new->dim = (t_ivec2){ft_atoi(split[1]), ft_atoi(split[0])};
		ft_memdel2d(split);
	}
	else
		ft_memdel((void**)&new);
	return (new);
}

t_move		*ft_setmoves(int fd)
{
	t_move	*new;
	char	*line;
	int		ret;
	t_ivec2	pos;

	if (!(new = (t_move*)ft_memalloc(sizeof(t_move))))
		return (NULL);
	pos = (t_ivec2){0, 0};
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == 'O' || line[0] == 'X')
		{
			new->pid = line[0];
			get_coords(line, &(new->coords));
			break ;
		}
		update_pos(new, &pos, line);
		free(line);
	}
	if (ret <= 0)
		ft_memdel((void**)&new);
	else
		update_other(new);
	return (new);
}

void		filler_setup(t_map *map)
{
	t_filler	*game;
	t_move		*tmp;
	t_list		*tmp_lst;
	size_t		size;

	game = filler_init();
	if (game == NULL)
		exit(EXIT_FAILURE);
	map->more = game;
	size = sizeof(t_move);
	while ((tmp = ft_setmoves(game->fd)))
	{
		tmp_lst = ft_lstnew(tmp, size);
		ft_lstpush2(&(game->moves), tmp_lst);
	}
}

int			draw_move(t_win *win, t_move *mv)
{
	t_map	*map;
	int		i;
	t_ivec2	pos;
	int		index;

	map = win->map;
	ft_memcpy(&pos, &(mv->coords), sizeof(t_ivec2));
	i = 0;
	while (i < mv->nbstar)
	{
		index = (pos.x + mv->tab[i].x) + \
				(mv->tab[i].y + pos.y) * map->width;
		map->tab[index].color = mv->tab[i].color;
		i++;
	}
	draw_map(map, *win, g_proj);
	return (1);
}
