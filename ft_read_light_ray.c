/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_light_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:20:45 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/13 13:33:13 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_read_light_ray(t_objects *obj, char **tmp)
{
	if (tmp[0] && tmp[3] && ft_strcmp(tmp[0], "ray") == 0)
	{
		obj->ray->p0.x = ft_atoi(tmp[1] + 1);
		obj->ray->p0.y = ft_atoi(tmp[2]);
		obj->ray->p0.z = ft_atoi(tmp[3]);
		return (1);
	}
	else if (tmp[0] && tmp[4] && ft_strcmp(tmp[0], "light") == 0)
	{
		obj->light->p0.x = ft_atoi(tmp[1] + 1);
		obj->light->p0.y = ft_atoi(tmp[2]);
		obj->light->p0.z = ft_atoi(tmp[3]);
		obj->light->color = ft_color_to_arr(ft_atoi_base(tmp[4] + 2, 16));
		return (1);
	}
	return (0);
}
