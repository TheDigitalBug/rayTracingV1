/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 19:47:03 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/12 16:26:19 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec		ft_vector(double x, double y, double z, double w)
{
	t_vec v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return (v);
}

t_vec		ft_rotate(t_vec v, t_objects *obj, char axis)
{
	t_matrix	m;
	t_vec		dir;

	if (axis == 'x')
	{
		m.r1 = ft_vector(1, 0, 0, 0);
		m.r2 = ft_vector(0, cos(obj->angle_rot), -sin(obj->angle_rot), 0);
		m.r3 = ft_vector(0, sin(obj->angle_rot), cos(obj->angle_rot), 0);
	}
	else if (axis == 'y')
	{
		m.r1 = ft_vector(cos(obj->angle_rot), 0, sin(obj->angle_rot), 0);
		m.r2 = ft_vector(0, 1, 0, 0);
		m.r3 = ft_vector(-sin(obj->angle_rot), 0, cos(obj->angle_rot), 0);
	}
	else if (axis == 'z')
	{
		m.r1 = ft_vector(cos(obj->angle_rot), -sin(obj->angle_rot), 0, 0);
		m.r2 = ft_vector(sin(obj->angle_rot), cos(obj->angle_rot), 0, 0);
		m.r3 = ft_vector(0, 0, 1, 0);
	}
	dir.x = ft_vector_mult_vector(m.r1, v);
	dir.y = ft_vector_mult_vector(m.r2, v);
	dir.z = ft_vector_mult_vector(m.r3, v);
	return (dir);
}

static void	ft_rotate_poly(t_list *list, t_objects *obj, char axis)
{
	list->poly->ver1 = ft_rotate(list->poly->ver1, obj, axis);
	list->poly->ver2 = ft_rotate(list->poly->ver2, obj, axis);
	list->poly->ver3 = ft_rotate(list->poly->ver3, obj, axis);
}

static void	ft_rotate_plane(t_list *list, t_objects *obj, char axis)
{
	list->plane->v = ft_rotate(list->plane->v, obj, axis);
	list->plane->c = ft_rotate(list->plane->c, obj, axis);
}

void		ft_rotate_objects(t_objects *obj, char axis)
{
	t_list *list;

	list = obj->head;
	while (list)
	{
		if (list->id == 0)
			list->sph->p = ft_rotate(list->sph->p, obj, axis);
		else if (list->id == 1)
		{
			list->cone->c = ft_rotate(list->cone->c, obj, axis);
			list->cone->v = ft_rotate(list->cone->v, obj, axis);
		}
		else if (list->id == 2)
		{
			list->cyl->c = ft_rotate(list->cyl->c, obj, axis);
			list->cyl->v = ft_rotate(list->cyl->v, obj, axis);
		}
		else if (list->id == 3)
			ft_rotate_plane(list, obj, axis);
		else if (list->id == 4)
			ft_rotate_poly(list, obj, axis);
		list = list->next;
	}
	obj->light->p0 = ft_rotate(obj->light->p0, obj, axis);
}
