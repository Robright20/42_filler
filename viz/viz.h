/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <robright28@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 02:59:24 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/21 23:58:43 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZ_H
# define VIZ_H
# include "../filler.h"
# include "fractol.h"

void	ft_background_color(t_img *img, int color);
void	ft_create_img(t_env *env, int color, t_ivec2 coords);
void	ft_apply_buf(t_env *env, int img_pos);
void	fill_buffer(int fd, char **buf);
int		ft_update(t_env *env);
#endif
