/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 12:35:12 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/12 14:03:47 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_list	*ft_create_elem(void *object, int id)
{
	t_list	*new;

	new = NULL;
	new = malloc(sizeof(t_list));
	new->id = id;
	new->next = NULL;
	if (id == 0)
		new->sph = (t_sphere*)object;
	if (id == 1)
		new->cone = (t_cone*)object;
	if (id == 2)
		new->cyl = (t_cyl*)object;
	if (id == 3)
		new->plane = (t_plane*)object;
	if (id == 4)
		new->poly = (t_poly*)object;
	return (new);
}
