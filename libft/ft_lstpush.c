/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:29:21 by fokrober          #+#    #+#             */
/*   Updated: 2019/12/22 15:57:18 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush(t_list *elm, t_list *new)
{
	if (!elm && !new)
		return (NULL);
	while (elm->next)
		elm = elm->next;
	return ((elm->next = new));
}

void	ft_lstpush2(t_list **elm_params, t_list *new)
{
	t_list	*elm;

	if (!elm_params)
		return ;
	if (!(elm = *elm_params))
	{
		*elm_params = new;
		return ;
	}
	while (elm->next)
		elm = elm->next;
	elm->next = new;
}
