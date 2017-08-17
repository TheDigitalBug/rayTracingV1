/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:55:19 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/12 12:39:15 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_intersec_sphere(t_list *list, t_vec ray_dir, t_vec ray_p0)
{
	double a;
	double b;
	double c;
	double d;

	a = ft_vector_scal_prod(ray_dir, ray_dir);
	b = 2 * ft_vector_scal_prod(ray_dir, ft_vector_sub(ray_p0, list->sph->p));
	c = ft_vector_scal_prod(ft_vector_sub(ray_p0, list->sph->p),
			ft_vector_sub(ray_p0, list->sph->p)) - list->sph->r * list->sph->r;
	d = b * b - 4 * a * c;
	if (d >= 0)
	{
		list->sph->t = (-b - sqrt(d)) / (2 * a);
		list->sph->inters = ft_intersection_point(list->sph->t,
				ray_dir, ray_p0);
		list->sph->normal = ft_vector_sub(list->sph->inters, list->sph->p);
	}
	else
		list->sph->t = 0;
	return (d);
}
