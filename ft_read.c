/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:06:20 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/15 12:31:25 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_set_static(t_objects *obj)
{
	obj->fov = (90 * 3.14) / (double)180;
	obj->ambient_coeff = 0.01;
	obj->aspectratio = WID / (double)HEIG;
	obj->angle = tan(obj->fov / 2);
	obj->specular_pow = 256;
	obj->angle_rot = 0;
	obj->shadow_coef = 0;
	if (!(obj->ray = (t_ray*)malloc(sizeof(t_ray))))
		exit(0);
	if (!(obj->light = (t_light*)malloc(sizeof(t_light))))
		exit(0);
}

static int	ft_read_check(int fd, t_objects *obj)
{
	char buf[1];

	if (read(fd, buf, 0) == -1 || fd < 0)
	{
		write(1, COL_RED, 5);
		write(1, "WRONG FILE\n", 11);
		write(1, COL_DEFAULT, 5);
		return (0);
	}
	ft_set_static(obj);
	return (1);
}

void		ft_read(t_objects *obj)
{
	int		fd;
	char	*line;
	char	**tmp;

	if (ft_read_check(fd = open(obj->file_name, O_RDONLY), obj) != 1)
		exit(1);
	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(line, ' ');
		if (ft_read_cone(obj, tmp) == 1)
			;
		else if (ft_read_cyl(obj, tmp) == 1)
			;
		else if (ft_read_sphere(obj, tmp) == 1)
			;
		else if (ft_read_plane(obj, tmp) == 1)
			;
		else if (ft_read_poly(obj, tmp) == 1)
			;
		else if (ft_read_light_ray(obj, tmp) == 1)
			;
		ft_free_split(tmp, line);
	}
	obj->ambient_color = ft_color_coeff(obj->ambient_coeff, obj->light->color);
	close(fd);
}
