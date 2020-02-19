/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <robright28@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:51:09 by fokrober          #+#    #+#             */
/*   Updated: 2020/02/19 15:53:30 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int     ft_sprintf(char *restrict str, const char *fmt, ...)
{
    va_list ap;
    int     start;
    int     end;
    int     size;
    char    *s;
    int     len;

    start = 0;
    end = 0;
    size = 0;
    va_start(ap, fmt);
    while (fmt[end])
    {
        if (!ft_strncmp(&fmt[end], "%s", 2))
        {
            ft_memcpy(&str[size], &fmt[start], end - start);
            size += end - start;
            start = end + 2;
            end = start;
            s = va_arg(ap, char *);
            len = ft_strlen(s);
            ft_memcpy(&str[size], s, len);
            size += len;
            continue ;
        }
        end++;
    }
    ft_memcpy(&str[size], &fmt[start], end - start);
    size += end - start;
    va_end(ap);
    return (size);
}