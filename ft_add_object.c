/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 12:32:42 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/12 15:05:39 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_add_object(t_list **head, void *object, int id)
{
	t_list	*new;

	if (*head)
	{
		new = ft_create_elem(object, id);
		new->next = *head;
		*head = new;
	}
	else
		*head = ft_create_elem(object, id);
}
