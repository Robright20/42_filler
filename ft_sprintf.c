/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <robright28@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:51:09 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/21 23:26:52 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_str_replace(char *str, const char *fmt, t_ivec3 *p, va_list ap)
{
	int		len;
	char	*s;

	ft_memcpy(&str[p->z], &fmt[p->x], p->y - p->x);
	p->z += p->y - p->x;
	p->x = p->y + 2;
	p->y = p->x;
	s = va_arg(ap, char *);
	len = ft_strlen(s);
	ft_memcpy(&str[p->z], s, len);
	p->z += len;
}

int		ft_sprintf(char *restrict str, const char *fmt, ...)
{
	va_list ap;
	t_ivec3	params;

	va_start(ap, fmt);
	params = (t_ivec3){0, 0, 0};
	while (fmt[params.y])
	{
		if (!ft_strncmp(&fmt[params.y], "%s", 2))
		{
			ft_str_replace(str, fmt, &params, ap);
			continue ;
		}
		params.y++;
	}
	ft_memcpy(&str[params.z], &fmt[params.x], params.y - params.x);
	params.z += params.y - params.x;
	va_end(ap);
	return (params.z);
}
