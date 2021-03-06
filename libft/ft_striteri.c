/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 02:33:31 by fokrober          #+#    #+#             */
/*   Updated: 2019/05/04 19:14:20 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;

	if (s && f)
	{
		i = 0;
		while (*s)
		{
			f(i, s);
			s++;
			i++;
		}
	}
}

void	ft_striteri2(char *s, void (*f)(unsigned int, char *, void *), void *p)
{
	int i;

	if (s && f)
	{
		i = 0;
		while (*s)
		{
			f(i, s, p);
			s++;
			i++;
		}
	}
}
