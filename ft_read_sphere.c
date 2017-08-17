/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 12:51:41 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/12 13:35:28 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_read_sphere(t_objects *obj, char **tmp)
{
	t_sphere *sph;

	if (tmp[0] && tmp[5] && ft_strcmp(tmp[0], "sphere") == 0)
	{
		if (!(sph = (t_sphere*)malloc(sizeof(t_sphere))))
			exit(0);
		sph->p.x = ft_atoi(tmp[1] + 1);
		sph->p.y = ft_atoi(tmp[2]);
		sph->p.z = ft_atoi(tmp[3]);
		sph->r = ft_atoi(tmp[4]);
		sph->color = ft_color_to_arr(ft_atoi_base(tmp[5] + 2, 16));
		ft_add_object(&(obj->head), sph, 0);
		return (1);
	}
	return (0);
}
