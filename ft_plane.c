/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:12:40 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/13 17:50:02 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_intersec_plane(t_list *list, t_vec ray_dir, t_vec ray_p0)
{
	if (ft_vector_scal_prod(ray_dir, list->plane->v) == 0)
		return (-1);
	list->plane->t = ft_vector_scal_prod(
		list->plane->v, ft_vector_sub(list->plane->c, ray_p0)) /
		ft_vector_scal_prod(ray_dir, list->plane->v);
	list->plane->inters = ft_intersection_point(list->plane->t,
			ray_dir, ray_p0);
	if (list->plane->t < 0)
		return (-1);
	list->plane->normal = list->plane->v;
	return (list->plane->t);
}
