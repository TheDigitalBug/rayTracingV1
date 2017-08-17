/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 12:06:31 by kkotliar          #+#    #+#             */
/*   Updated: 2017/04/28 13:34:25 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_put_pixel(t_mlx *m, int x, int y, t_color col)
{
	int i;

	i = x * 4 + y * m->size_line;
	m->color[i] = col.r;
	m->color[++i] = col.g;
	m->color[++i] = col.b;
}
