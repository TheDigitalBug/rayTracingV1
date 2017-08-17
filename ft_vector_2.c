/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:37:18 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/05 19:45:53 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	ft_vector_unit(t_vec v)
{
	double	modul;
	t_vec	unit_vector;

	modul = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	unit_vector.x = v.x / modul;
	unit_vector.y = v.y / modul;
	unit_vector.z = v.z / modul;
	return (unit_vector);
}

t_vec	ft_vector_add(t_vec v1, t_vec v2)
{
	t_vec v3;

	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	v3.z = v1.z + v2.z;
	return (v3);
}

t_vec	ft_vector_mult(t_vec v1, double nb)
{
	t_vec v2;

	v2.x = v1.x * nb;
	v2.y = v1.y * nb;
	v2.z = v1.z * nb;
	return (v2);
}

double	ft_vector_mult_vector(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w);
}
