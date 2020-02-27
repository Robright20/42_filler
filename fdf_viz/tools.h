/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 05:48:58 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/27 05:51:35 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

void		ft_count_star(char *s, int *nbstar);
void		update_pos(t_move *mv, t_ivec2 *pos, char *line);
void		update_other(t_move *mv);
int			get_coords(char *line, t_ivec2 *coords);
#endif
