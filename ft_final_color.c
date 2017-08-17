/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 15:29:14 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/15 15:15:15 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_diffuse_color(t_objects *obj, t_vec light_p0, t_vec normal_obj,
		t_vec inters_point)
{
	t_vec	unit_normal;
	t_vec	unitlight_t;

	unit_normal = ft_vector_unit(normal_obj);
	unitlight_t = ft_vector_unit(ft_vector_sub(light_p0, inters_point));
	obj->diffuse_factor = ft_vector_scal_prod(unit_normal, unitlight_t);
	obj->diffuse_factor = ft_max(obj->diffuse_factor, 0);
}

void		ft_specular_color(t_objects *obj, t_vec light_p0, t_vec normal_obj,
		t_vec inters_point)
{
	t_vec	unit_normal;
	t_vec	unitlight_t;
	t_vec	half;
	t_vec	unit_view;

	unit_normal = ft_vector_unit(normal_obj);
	unitlight_t = ft_vector_unit(ft_vector_sub(light_p0, inters_point));
	unit_view = ft_vector_unit(ft_vector_sub(obj->ray->p0, inters_point));
	half = ft_vector_add(unit_view, unitlight_t);
	half = ft_vector_unit(half);
	obj->specular_factor = pow(ft_vector_scal_prod(unit_normal, half),
			obj->specular_pow);
	obj->specular_factor = ft_max(obj->specular_factor, 0);
}

t_color		ft_color_of_pixel(t_objects *obj, int specular_on_off)
{
	ft_diffuse_color(obj, obj->light->p0, obj->obj_normal, obj->inter_point);
	ft_specular_color(obj, obj->light->p0, obj->obj_normal, obj->inter_point);
	obj->diffuse_color = ft_color_coeff(obj->diffuse_factor,
			obj->light->color);
	if (specular_on_off == 0 && obj->shadow_coef != 1)
		obj->specular_factor = 0;
	obj->specular_color = ft_color_coeff(obj->specular_factor,
			obj->light->color);
	obj->color = ft_color_mult(ft_color_add(obj->ambient_color,
			obj->diffuse_color), ft_color_add(obj->specular_color, obj->color));
	return (obj->color);
}

static void	ft_pointer_to_intersection(double (*intersection[])())
{
	intersection[0] = ft_intersec_sphere;
	intersection[1] = ft_intersec_cone;
	intersection[2] = ft_intersec_cyl;
	intersection[3] = ft_intersec_plane;
	intersection[4] = ft_intersec_poly;
}

t_color		ft_final_color(t_objects *obj, t_list *head, t_vec inter_point)
{
	t_list	*l;
	int		i;
	double	(*intersection[5])(t_list *l, t_vec ray_dir, t_vec ray_p0);

	ft_pointer_to_intersection(intersection);
	i = 0;
	if (obj->number_of_list == -1)
		return (obj->color = ft_color_make(0, 0, 0));
	l = head;
	while (l)
	{
		if (obj->number_of_list != i++ && intersection[l->id](l, ft_vector_unit(
		ft_vector_sub(inter_point, obj->light->p0)), obj->light->p0) > 0)
		{
			if ((l->id == 0 && obj->light_t > l->sph->t && l->sph->t > 0) ||
			(l->id == 1 && obj->light_t > l->cone->t && l->cone->t > 0) ||
			(l->id == 2 && obj->light_t > l->cyl->t && l->cyl->t > 0) ||
			(l->id == 3 && obj->light_t > l->plane->t && l->plane->t > 0) ||
			(l->id == 4 && obj->light_t > l->poly->t && l->poly->t > 0))
				return (ft_color_coeff(obj->shadow_coef,
							ft_color_of_pixel(obj, 0)));
		}
		l = l->next;
	}
	return (obj->color = ft_color_of_pixel(obj, 1));
}
