/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:12:41 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/13 16:45:51 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_read_plane(t_objects *obj, char **tmp)
{
	t_plane	*plane;

	if (tmp[0] && tmp[7] && ft_strcmp(tmp[0], "plane") == 0)
	{
		if (!(plane = (t_plane*)malloc(sizeof(t_plane))))
			exit(0);
		plane->c.x = ft_atoi(tmp[1] + 1);
		plane->c.y = ft_atoi(tmp[2]);
		plane->c.z = ft_atoi(tmp[3]);
		plane->v.x = ft_atoi(tmp[4] + 1);
		plane->v.y = ft_atoi(tmp[5]);
		plane->v.z = ft_atoi(tmp[6]);
		plane->color = ft_color_to_arr(ft_atoi_base(tmp[7] + 2, 16));
		ft_add_object(&(obj->head), plane, 3);
		return (1);
	}
	return (0);
}
