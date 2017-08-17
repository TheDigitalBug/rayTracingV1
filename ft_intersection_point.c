/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_point.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:33:04 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/08 13:09:12 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	ft_intersection_point(double t, t_vec ray_dir, t_vec ray_p0)
{
	t_vec intersection_point;

	intersection_point.x = ray_dir.x * t + ray_p0.x;
	intersection_point.y = ray_dir.y * t + ray_p0.y;
	intersection_point.z = ray_dir.z * t + ray_p0.z;
	return (intersection_point);
}
