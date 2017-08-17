/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_cyl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:09:05 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/12 13:35:38 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_read_cyl(t_objects *obj, char **tmp)
{
	t_cyl	*cyl;

	if (tmp[0] && tmp[8] && ft_strcmp(tmp[0], "cylinder") == 0)
	{
		if (!(cyl = (t_cyl*)malloc(sizeof(t_cyl))))
			exit(0);
		cyl->c.x = ft_atoi(tmp[1] + 1);
		cyl->c.y = ft_atoi(tmp[2]);
		cyl->c.z = ft_atoi(tmp[3]);
		cyl->v.x = ft_atoi(tmp[4] + 1);
		cyl->v.y = ft_atoi(tmp[5]);
		cyl->v.z = ft_atoi(tmp[6]);
		cyl->r = ft_atoi(tmp[7]);
		cyl->color = ft_color_to_arr(ft_atoi_base(tmp[8] + 2, 16));
		ft_add_object(&(obj->head), cyl, 2);
		return (1);
	}
	return (0);
}
