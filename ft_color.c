/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 15:54:51 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/11 12:13:57 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color	ft_color_to_arr(int color_int)
{
	t_color color;

	color.r = ((color_int) & 0xFF);
	color.g = ((color_int >> 8) & 0xFF);
	color.b = ((color_int >> 16) & 0xFF);
	return (color);
}

t_color	ft_color_coeff(double coeff, t_color color)
{
	t_color new_color;

	new_color.r = (double)color.r * coeff;
	new_color.g = (double)color.g * coeff;
	new_color.b = (double)color.b * coeff;
	return (new_color);
}

t_color	ft_color_add(t_color c1, t_color c2)
{
	t_color new_color;

	if ((new_color.r = c1.r + c2.r) > 255)
		new_color.r = 255;
	if ((new_color.g = c1.g + c2.g) > 255)
		new_color.g = 255;
	if ((new_color.b = c1.b + c2.b) > 255)
		new_color.b = 255;
	return (new_color);
}

t_color	ft_color_mult(t_color c1, t_color c2)
{
	t_color new_color;

	if ((new_color.r = (c1.r * c2.r) / 255) > 255)
		new_color.r = 255;
	if ((new_color.g = (c1.g * c2.g) / 255) > 255)
		new_color.g = 255;
	if ((new_color.b = (c1.g * c2.b) / 255) > 255)
		new_color.b = 255;
	return (new_color);
}

t_color	ft_color_make(int r, int g, int b)
{
	t_color new_color;

	new_color.r = r;
	new_color.g = g;
	new_color.b = b;
	return (new_color);
}
