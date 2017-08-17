/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_cone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:05:10 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/12 13:35:52 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_read_cone(t_objects *obj, char **tmp)
{
	t_cone	*cone;

	if (tmp[0] && tmp[8] && ft_strcmp(tmp[0], "cone") == 0)
	{
		if (!(cone = (t_cone*)malloc(sizeof(t_cone))))
			exit(0);
		cone->c.x = ft_atoi(tmp[1] + 1);
		cone->c.y = ft_atoi(tmp[2]);
		cone->c.z = ft_atoi(tmp[3]);
		cone->v.x = ft_atoi(tmp[4] + 1);
		cone->v.y = ft_atoi(tmp[5]);
		cone->v.z = ft_atoi(tmp[6]);
		cone->angel = ft_atoi(tmp[7]);
		cone->color = ft_color_to_arr(ft_atoi_base(tmp[8] + 2, 16));
		ft_add_object(&(obj->head), cone, 1);
		return (1);
	}
	return (0);
}
