/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:43:58 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/12 17:25:52 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_cone_normal(t_list *list, t_vec ray_dir, t_vec ray_p0)
{
	double	m;

	list->cone->inters = ft_intersection_point(list->cone->t, ray_dir, ray_p0);
	m = ft_vector_scal_prod(ray_dir, list->cone->v) * list->cone->t +
		ft_vector_scal_prod(ft_vector_sub(ray_p0, list->cone->c),
			list->cone->v);
	list->cone->normal = ft_vector_sub(
	ft_vector_sub(list->cone->inters, list->cone->c), ft_vector_mult(
	list->cone->v, (1 + pow(tan(list->cone->angel * PI / 180), 2)) * m));
}

double		ft_intersec_cone(t_list *list, t_vec ray_dir, t_vec ray_p0)
{
	double	a;
	double	b;
	double	c;
	double	d;
	t_vec	co;

	co = ft_vector_sub(ray_p0, list->cone->c);
	list->cone->v = ft_vector_unit(list->cone->v);
	a = ft_vector_scal_prod(ray_dir, ray_dir) - (1 + pow(tan(list->cone->angel
		* PI / 180), 2)) * pow(ft_vector_scal_prod(ray_dir, list->cone->v), 2);
	b = 2 * (ft_vector_scal_prod(ray_dir, co) - (1 + pow(tan(list->cone->angel
		* PI / 180), 2)) * ft_vector_scal_prod(ray_dir, list->cone->v) *
		ft_vector_scal_prod(co, list->cone->v));
	c = ft_vector_scal_prod(co, co) - (1 + pow(tan(list->cone->angel *
		PI / 180), 2)) * pow(ft_vector_scal_prod(co, list->cone->v), 2);
	if ((d = b * b - 4 * a * c) >= 0)
	{
		if ((list->cone->t = (-b - sqrt(d)) / (2 * a)) < 0 &&
				(-b + sqrt(d)) / (2 * a) < 0)
			return (list->cone->t = -1);
		ft_cone_normal(list, ray_dir, ray_p0);
	}
	else
		list->cone->t = 0;
	return (d);
}
