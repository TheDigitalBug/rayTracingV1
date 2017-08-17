/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 12:13:08 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/12 17:34:37 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_cyl_normal(t_list *list, t_vec ray_dir, t_vec ray_p0)
{
	double	m;

	list->cyl->inters = ft_intersection_point(list->cyl->t, ray_dir,
		ray_p0);
	m = ft_vector_scal_prod(ray_dir, list->cyl->v) * list->cyl->t +
		ft_vector_scal_prod(ft_vector_sub(ray_p0, list->cyl->c), list->cyl->v);
	list->cyl->normal = ft_vector_sub(ft_vector_sub(list->cyl->inters,
	list->cyl->c), ft_vector_mult(list->cyl->v, m));
}

double		ft_intersec_cyl(t_list *list, t_vec ray_dir, t_vec ray_p0)
{
	double	a;
	double	b;
	double	c;
	double	d;
	t_vec	co;

	list->cyl->v = ft_vector_unit(list->cyl->v);
	co = ft_vector_sub(ray_p0, list->cyl->c);
	a = ft_vector_scal_prod(ray_dir, ray_dir) -
		pow(ft_vector_scal_prod(ray_dir, list->cyl->v), 2);
	b = 2 * (ft_vector_scal_prod(ray_dir, co) - ft_vector_scal_prod(ray_dir,
			list->cyl->v) * ft_vector_scal_prod(co, list->cyl->v));
	c = ft_vector_scal_prod(co, co) -
		pow(ft_vector_scal_prod(co, list->cyl->v), 2) - pow(list->cyl->r, 2);
	d = b * b - 4 * a * c;
	if (d >= 0)
	{
		list->cyl->t = (-b - sqrt(d)) / (2 * a);
		if (list->cyl->t < 0 && (-b + sqrt(d)) / (2 * a) < 0)
			return (list->cyl->t = -1);
		ft_cyl_normal(list, ray_dir, ray_p0);
	}
	else
		list->cyl->t = 0;
	return (d);
}
