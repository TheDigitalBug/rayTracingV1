/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_polygon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:51:04 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/15 09:46:16 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_check_point(t_list *list, t_vec a, t_vec b, t_vec c)
{
	t_vec	p;

	p = ft_vector_sub(list->poly->inters, list->poly->ver3);
	if (ft_vector_scal_prod(list->poly->normal, ft_vector_cross_prod(a, p)) < 0)
		return (-1);
	p = ft_vector_sub(list->poly->inters, list->poly->ver1);
	if (ft_vector_scal_prod(list->poly->normal, ft_vector_cross_prod(b, p)) < 0)
		return (-1);
	p = ft_vector_sub(list->poly->inters, list->poly->ver2);
	if (ft_vector_scal_prod(list->poly->normal, ft_vector_cross_prod(c, p)) < 0)
		return (-1);
	return (1);
}

double		ft_intersec_poly(t_list *list, t_vec ray_dir, t_vec ray_p0)
{
	t_vec	a;
	t_vec	b;
	t_vec	c;

	a = ft_vector_sub(list->poly->ver1, list->poly->ver3);
	b = ft_vector_sub(list->poly->ver2, list->poly->ver1);
	c = ft_vector_sub(list->poly->ver3, list->poly->ver2);
	list->poly->normal = ft_vector_cross_prod(c, a);
	list->poly->t = ft_vector_scal_prod(list->poly->normal,
			ft_vector_sub(list->poly->ver1, ray_p0)) /
		ft_vector_scal_prod(list->poly->normal, ray_dir);
	if (list->poly->t < 0)
		return (-1);
	list->poly->inters = ft_intersection_point(list->poly->t, ray_dir, ray_p0);
	if (ft_check_point(list, a, b, c) == -1)
		return (-1);
	if (ft_vector_scal_prod(list->poly->normal,
				ft_vector_sub(list->poly->light->p0, list->poly->ver2)) < 0)
		list->poly->normal = ft_vector_mult(list->poly->normal, -1);
	return (1);
}
