/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_poly.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:17:39 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/13 16:46:04 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_read_poly(t_objects *obj, char **tmp)
{
	t_poly	*poly;

	if (tmp[0] && tmp[10] && ft_strcmp(tmp[0], "polygon") == 0)
	{
		if (!(poly = (t_poly*)malloc(sizeof(t_poly))))
			exit(0);
		poly->ver1.x = ft_atoi(tmp[1] + 1);
		poly->ver1.y = ft_atoi(tmp[2]);
		poly->ver1.z = ft_atoi(tmp[3]);
		poly->ver2.x = ft_atoi(tmp[4] + 1);
		poly->ver2.y = ft_atoi(tmp[5]);
		poly->ver2.z = ft_atoi(tmp[6]);
		poly->ver3.x = ft_atoi(tmp[7] + 1);
		poly->ver3.y = ft_atoi(tmp[8]);
		poly->ver3.z = ft_atoi(tmp[9]);
		poly->color = ft_color_to_arr(ft_atoi_base(tmp[10] + 2, 16));
		poly->light = obj->light;
		ft_add_object(&(obj->head), poly, 4);
		return (1);
	}
	return (0);
}
