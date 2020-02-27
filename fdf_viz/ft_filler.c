/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 04:18:57 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/27 06:37:14 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_count_star(char *s, int *nbstar)
{
	while (*s)
	{
		if (*s == '*')
			*nbstar += 1;
		s++;
	}
}

void		update_pos(t_move *new, t_ivec2 *pos, char *line)
{
	size_t	oldsize;
	t_point	*tmp;
	int		i;

	oldsize = new->nbstar * sizeof(t_point);
	ft_count_star(line, &(new->nbstar));
	tmp = (t_point*)ft_memalloc(new->nbstar * sizeof(t_point));
	if (new->tab && pos->y)
	{
		ft_memcpy(tmp, new->tab, oldsize);
		free(new->tab);
	}
	new->tab = tmp;
	i = oldsize;
	pos->x = 0;
	while (i < new->nbstar)
	{
		new->tab[i].x = pos->x;
		new->tab[i].y = pos->y;
		i++;
		pos->x++;
	}
	pos->y++;
}

void		update_other(t_move *new)
{
	int		i;

	i = 0;
	while (i < new->nbstar)
	{
		new->tab[i].z = (new->pid == 'O') ? 2 : 4;
		new->tab[i].color = (new->pid == 'O') ? RED : GREEN;
		i++;
	}
}

int			get_coords(char *line, t_ivec2 *coords)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	*coords = (t_ivec2){ft_atoi(split[1]), ft_atoi(split[2])};
	ft_memdel2d(split);
	return (1);
}
