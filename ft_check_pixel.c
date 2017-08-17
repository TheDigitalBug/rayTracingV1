/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:19:16 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/15 15:22:05 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_chek_sphere(t_objects *obj, t_list *list, int i)
{
	if (ft_intersec_sphere(list, obj->ray->d, obj->ray->p0) >= 0
			&& obj->min_t >= list->sph->t)
	{
		obj->min_t = list->sph->t;
		obj->obj_normal = list->sph->normal;
		obj->color = list->sph->color;
		obj->number_of_list = i;
		obj->inter_point = list->sph->inters;
		ft_intersec_sphere(list, ft_vector_unit(ft_vector_sub(list->sph->inters,
						obj->light->p0)), obj->light->p0);
		obj->light_t = list->sph->t;
	}
}

void	ft_chek_cone(t_objects *obj, t_list *list, int i)
{
	if (ft_intersec_cone(list, obj->ray->d, obj->ray->p0) >= 0 &&
			obj->min_t >= list->cone->t)
	{
		obj->min_t = list->cone->t;
		obj->color = list->cone->color;
		obj->obj_normal = list->cone->normal;
		obj->number_of_list = i;
		obj->inter_point = list->cone->inters;
		ft_intersec_cone(list, ft_vector_unit(ft_vector_sub(list->cone->inters,
						obj->light->p0)), obj->light->p0);
		obj->light_t = list->cone->t;
	}
}

void	ft_chek_cyl(t_objects *obj, t_list *list, int i)
{
	if (ft_intersec_cyl(list, obj->ray->d, obj->ray->p0) >= 0 &&
			obj->min_t >= list->cyl->t)
	{
		obj->min_t = list->cyl->t;
		obj->color = list->cyl->color;
		obj->obj_normal = list->cyl->normal;
		obj->number_of_list = i;
		obj->inter_point = list->cyl->inters;
		ft_intersec_cyl(list, ft_vector_unit(ft_vector_sub(list->cyl->inters,
						obj->light->p0)), obj->light->p0);
		obj->light_t = list->cyl->t;
	}
}

void	ft_chek_plane(t_objects *obj, t_list *list, int i)
{
	if (ft_intersec_plane(list, obj->ray->d, obj->ray->p0) > 0 &&
			obj->min_t >= list->plane->t)
	{
		obj->min_t = list->plane->t;
		obj->color = list->plane->color;
		obj->obj_normal = list->plane->normal;
		obj->number_of_list = i;
		obj->inter_point = list->plane->inters;
		ft_intersec_plane(list, ft_vector_unit(ft_vector_sub(
					list->plane->inters, obj->light->p0)), obj->light->p0);
		obj->light_t = list->plane->t;
	}
}

void	ft_chek_poly(t_objects *obj, t_list *list, int i)
{
	if (ft_intersec_poly(list, obj->ray->d, obj->ray->p0) > 0 &&
			obj->min_t >= list->poly->t)
	{
		obj->min_t = list->poly->t;
		obj->color = list->poly->color;
		obj->obj_normal = list->poly->normal;
		obj->number_of_list = i;
		obj->inter_point = list->poly->inters;
		ft_intersec_poly(list, ft_vector_unit(ft_vector_sub(list->poly->inters,
						obj->light->p0)), obj->light->p0);
		obj->light_t = list->poly->t;
	}
}
