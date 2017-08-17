/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:33:01 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/15 11:04:45 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_key_rotate(int keycode, t_objects *obj)
{
	if (keycode == 123 || keycode == 124)
	{
		obj->angle_rot = (keycode == 123) ? 0.1 : -0.1;
		ft_rotate_objects(obj, 'y');
	}
	if (keycode == 125 || keycode == 126)
	{
		obj->angle_rot = (keycode == 125) ? 0.1 : -0.1;
		ft_rotate_objects(obj, 'x');
	}
	if (keycode == 43 || keycode == 47)
	{
		obj->angle_rot = (keycode == 47) ? 0.1 : -0.1;
		ft_rotate_objects(obj, 'z');
	}
}

int			ft_key(int keycode, t_objects *obj)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 37)
	{
		obj->light->p0.x = (obj->mouse_x - obj->ray->p0.z / 2) * 2;
		obj->light->p0.y = (obj->mouse_y - obj->ray->p0.z / 2) * (-2);
	}
	(keycode == 69) ? obj->ambient_coeff += 0.1 : 1;
	obj->ambient_coeff = (obj->ambient_coeff > 1) ? 1 : obj->ambient_coeff;
	(keycode == 78) ? obj->ambient_coeff -= 0.1 : 1;
	if (obj->ambient_coeff < 0)
		obj->ambient_coeff = 0;
	(keycode == 92) ? obj->specular_pow *= 2 : 1;
	if (obj->specular_pow > 256)
		obj->specular_pow = 256;
	(keycode == 88) ? obj->specular_pow /= 2 : 1;
	obj->specular_pow = (obj->specular_pow < 2) ? 2 : obj->specular_pow;
	(keycode == 49) ? ft_free_list(obj) : (t_list*)1;
	(keycode == 49) ? ft_read(obj) : (t_list*)1;
	(keycode == 18) ? obj->shadow_coef = 1 : 1;
	(keycode == 19) ? obj->shadow_coef = 0.2 : 1;
	(keycode == 20) ? obj->shadow_coef = 0 : 1;
	ft_key_rotate(keycode, obj);
	ft_build_scene(obj);
	return (0);
}

int			ft_mouse(int button, int x, int y, t_objects *obj)
{
	if (button == 4 && ((x > 0 && x < 1000) && (y > 0 && y < 1000)))
		obj->ray->p0.z -= 100;
	if (button == 5 && ((x > 0 && x < 1000) && (y > 0 && y < 1000)))
		obj->ray->p0.z += 100;
	ft_build_scene(obj);
	return (0);
}

int			ft_mouse_move(int x, int y, t_objects *obj)
{
	if ((x > 0 && x < WID) && (y > 0 && y < HEIG))
	{
		obj->mouse_x = x;
		obj->mouse_y = y;
	}
	return (0);
}
