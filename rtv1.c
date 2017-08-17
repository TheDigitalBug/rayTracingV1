/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 12:16:07 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/17 10:08:02 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_intersec_first(t_objects *obj)
{
	t_list	*list;
	double	t_min;

	list = obj->head;
	while (list)
	{
		if (list->id == 0 &&
				ft_intersec_sphere(list, obj->ray->d, obj->ray->p0) > 0)
			return (t_min = list->sph->t);
		else if (list->id == 1 &&
				ft_intersec_cone(list, obj->ray->d, obj->ray->p0) > 0)
			return (t_min = list->cone->t);
		else if (list->id == 2 &&
				ft_intersec_cyl(list, obj->ray->d, obj->ray->p0) > 0)
			return (t_min = list->cyl->t);
		else if (list->id == 3 &&
				ft_intersec_plane(list, obj->ray->d, obj->ray->p0) > 0)
			return (t_min = list->plane->t);
		else if (list->id == 4 &&
				ft_intersec_poly(list, obj->ray->d, obj->ray->p0) > 0)
			return (t_min = list->poly->t);
		list = list->next;
	}
	return (t_min = 0);
}

void	ft_intersec_objects(t_objects *obj)
{
	t_list	*list;
	int		i;
	int		k;
	void	(*check[5])(t_objects *obj, t_list *list, int i);

	obj->min_t = ft_intersec_first(obj);
	check[0] = ft_chek_sphere;
	check[1] = ft_chek_cone;
	check[2] = ft_chek_cyl;
	check[3] = ft_chek_plane;
	check[4] = ft_chek_poly;
	obj->number_of_list = -1;
	i = 0;
	list = obj->head;
	while (list)
	{
		k = list->id;
		check[k](obj, list, i);
		i++;
		list = list->next;
	}
	if (obj->number_of_list == -1)
		obj->color = ft_color_make(0, 0, 0);
}

void	ft_build_scene(t_objects *obj)
{
	double	x;
	double	y;
	t_color	color;
	t_ray	px;

	obj->ambient_color = ft_color_coeff(obj->ambient_coeff, obj->light->color);
	y = 0;
	while (y < HEIG)
	{
		px.d.y = (1 - 2 * ((y + 0.5) / HEIG)) * obj->angle;
		x = 0;
		while (x < WID)
		{
			px.d.x = (2 * (x + 0.5) / WID - 1) * obj->angle * obj->aspectratio;
			px.d.z = -1;
			obj->ray->d = ft_vector_unit(px.d);
			ft_intersec_objects(obj);
			color = ft_final_color(obj, obj->head, obj->inter_point);
			ft_put_pixel(&(obj->m), (int)x, (int)y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(obj->m.mlx, obj->m.win, obj->m.img, 0, 0);
}

int		main(int argc, char **argv)
{
	t_objects	*obj;

	if (!(obj = (t_objects*)malloc(sizeof(t_objects))))
		exit(0);
	if (argc != 2)
	{
		write(1, COL_RED, 5);
		write(1, "usage: ./RTv1 sceneX.txt\n", 25);
		write(1, COL_DEFAULT, 5);
		exit(1);
	}
	obj->file_name = argv[1];
	ft_read(obj);
	obj->m.mlx = mlx_init();
	obj->m.win = mlx_new_window(obj->m.mlx, WID, HEIG, "RayTracer 2000");
	obj->m.img = mlx_new_image(obj->m.mlx, WID, HEIG);
	obj->m.color = mlx_get_data_addr(obj->m.img, &(obj->m.bpp),
			&(obj->m.size_line), &(obj->m.endian));
	ft_build_scene(obj);
	mlx_hook(obj->m.win, 2, 0, ft_key, obj);
	mlx_hook(obj->m.win, 6, 0, ft_mouse_move, obj);
	mlx_mouse_hook(obj->m.win, ft_mouse, obj);
	mlx_loop(obj->m.mlx);
	mlx_destroy_image(obj->m.mlx, obj->m.img);
	ft_free_all(obj);
}
