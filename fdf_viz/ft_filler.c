/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 04:18:57 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/27 01:36:08 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_filler	*filler_init(void)
{
	t_filler	*new;
	int			i;
	int			ret;
	char		**split;
	char		*line;

	new = (t_filler*)malloc(sizeof(t_filler));
	if (new == NULL)
		return (NULL);
	new->map = NULL;
	new->fd = open("filler.data", O_RDONLY);
	i = 2;
	while (i-- && (ret = get_next_line(new->fd, &line)) > 0)
	{
		line[0] = (line[0] == '1') ? 'O' : 'X';
		new->p[i] = line;
	}
	if (ret > 0 && (ret = get_next_line(new->fd, &line)) > 0)
	{
		split = ft_strsplit(line, ' ');
		new->dim.x = ft_atoi(split[1]);
		new->dim.y = ft_atoi(split[0]);
		ft_memdel2d(split);
	}
	else
	{
		free(new);
		return (NULL);
	}
	new->moves = NULL;
	return (new);
}

void		ft_count_star(char *s, int *nbstar)
{
	while (*s)
	{
		if (*s == '*')
			*nbstar += 1; 
		s++;
	}
}

void		update_pos(t_move *new, t_ivec2 pos, char *line)
{
	size_t	oldsize;
	t_point	*tmp;
	int		i;
	int		x;

	oldsize = new->nbstar * sizeof(t_point);
	ft_count_star(line, &(new->nbstar));
	tmp = (t_point*)ft_memalloc(new->nbstar * sizeof(t_point));
	if (new->tab && pos.y)
	{
		ft_memcpy(tmp, new->tab, oldsize);
		free(new->tab);
	}
	new->tab = tmp;
	i = oldsize;
	x = 0;
	while (i < new->nbstar)
	{
		new->tab[i].x = x;
		new->tab[i].y = pos.y;
		i++;
		x++;
	}
}

void	update_other(t_move *new)
{
	int		i;

	i = 0;
	while (i < new->nbstar)
	{
		new->tab[i].z = (new->pid == 'O') ? 2 : 4;
		new->tab[i].color = (new->pid == 'O') ? 0x00ff0000: 0x0000ff00;
		i++;
	}
}

t_move		*ft_setmoves(int fd)
{
	t_move	*new;
	char	*line;
	int		ret;
	t_ivec2	pos;
	char	**split;

	new = (t_move*)ft_memalloc(sizeof(t_move));
	if (new == NULL)
		return (NULL);
	line = NULL;
	pos = (t_ivec2){0, 0};
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == 'O' || line[0] == 'X')
		{
			new->pid = line[0];
			split = ft_strsplit(line, ' ');
			new->coords.x = ft_atoi(split[1]);
			new->coords.y = ft_atoi(split[2]);
			ft_memdel2d(split);
			break ;
		}
		update_pos(new, pos, line);
		pos.y++;
		free(line);
	}
	if (ret <= 0)
	{
		free(new);
		return (NULL);
	}
	update_other(new);
	return (new);
}

void		ft_put_move(t_move *mv)
{
	int i = 0;

	while (i < mv->nbstar)
	{
		printf("nbstar [%d] pid [%c]\n", mv->nbstar, mv->pid);
		printf("coords.x [%d] coords.y [%d]\n", mv->coords.x, mv->coords.y);
		printf("tab[0].x [%f] tab[0].y [%f]\n", mv->tab[i].x, mv->tab[i].y);
		printf("tab[0].z [%f] tab[0].color [%#010x]\n", mv->tab[i].z, mv->tab[i].color);
		i++;
	}
}

void		ft_puts_move(t_list *tmp_lst)
{
	while (tmp_lst)
	{
		ft_put_move(tmp_lst->content);
		tmp_lst = tmp_lst->next;
	}
}
void		filler_setup(t_map *map)
{
	t_filler	*game;
	t_move		*tmp;
	t_list		*tmp_lst;
	size_t		size;

	game = filler_init();
	if (game == NULL)
		exit(1);
	map->more = game;
	size = sizeof(t_move);
	while ((tmp = ft_setmoves(game->fd)))
	{
		tmp_lst = ft_lstnew(tmp, size);
		ft_lstpush2(&(game->moves), tmp_lst);
	}
	ft_puts_move(game->moves);
}

void	draw_move(t_win *win, t_move *mv, int projection)
{
	t_map	*map;
	int		i;
	t_ivec2	pos;
	int		index;

	map = win->map;
	i = 0;
	ft_memcpy(&pos, &(mv->coords), sizeof(t_ivec2));
	while (i < mv->nbstar)
	{
		index = pos.x + pos.y * map->width;
		map->tab[index].color = mv->tab[i].color;
		i++;
	}
	draw_map(map, *win, projection);
}
