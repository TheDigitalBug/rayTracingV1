/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 10:40:02 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/17 10:06:37 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "minilibx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# define WID 1000
# define HEIG 1000
# define PI 3.14
# define COL_RED "\x1B[31m"
# define COL_DEFAULT "\e[39m"

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				size_line;
	int				endian;
	char			*color;
}					t_mlx;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vec;

typedef struct		s_cone
{
	int				type;
	t_vec			c;
	t_vec			v;
	double			angel;
	double			t;
	t_color			color;
	t_vec			normal;
	t_vec			inters;
}					t_cone;

typedef struct		s_matrix
{
	t_vec			r1;
	t_vec			r2;
	t_vec			r3;
	t_vec			r4;
}					t_matrix;

typedef struct		s_sphere
{
	t_vec			p;
	double			t;
	int				r;
	t_color			color;
	t_vec			normal;
	t_vec			inters;
}					t_sphere;

typedef struct		s_cyl
{
	t_vec			c;
	t_vec			v;
	double			r;
	double			t;
	t_color			color;
	t_vec			normal;
	t_vec			inters;
}					t_cyl;

typedef struct		s_plane
{
	t_vec			c;
	t_vec			v;
	double			t;
	t_color			color;
	t_vec			normal;
	t_vec			inters;
}					t_plane;

typedef struct		s_ray
{
	t_vec			d;
	t_vec			p0;
	t_vec			p1;
}					t_ray;

typedef struct		s_light
{
	t_vec			d;
	t_vec			p0;
	t_color			color;
}					t_light;

typedef struct		s_poly
{
	t_vec			ver1;
	t_vec			ver2;
	t_vec			ver3;
	double			t;
	t_light			*light;
	t_color			color;
	t_vec			normal;
	t_vec			inters;
}					t_poly;

typedef struct		s_list
{
	t_sphere		*sph;
	t_cone			*cone;
	t_cyl			*cyl;
	t_plane			*plane;
	t_ray			*ray;
	t_light			*light;
	t_poly			*poly;
	int				id;
	struct s_list	*next;
}					t_list;

typedef struct		s_objects
{
	t_ray			*ray;
	t_light			*light;
	char			*file_name;
	int				mouse_x;
	int				mouse_y;
	double			aspectratio;
	double			fov;
	double			angle;
	t_mlx			m;
	double			ambient_coeff;
	t_color			ambient_color;
	int				specular_pow;
	t_color			specular_color;
	double			specular_factor;
	t_color			diffuse_color;
	double			diffuse_factor;
	t_color			color;
	int				number_of_list;
	double			light_t;
	t_vec			inter_point;
	t_vec			obj_normal;
	double			angle_rot;
	double			shadow_coef;
	t_list			*head;
	double			min_t;
}					t_objects;

void				ft_build_scene(t_objects *obj);
void				ft_intersec_objects(t_objects *obj);
t_vec				ft_intersection_point(double t, t_vec ray_dir,
		t_vec ray_p0);
double				ft_intersec_sphere(t_list *list, t_vec ray_dir,
		t_vec ray_p0);
double				ft_intersec_plane(t_list *list, t_vec ray_dir,
		t_vec ray_p0);
double				ft_intersec_cone(t_list *list, t_vec ray_dir,
		t_vec ray_p0);
double				ft_intersec_cyl(t_list *list, t_vec ray_dir,
		t_vec ray_p0);
void				ft_diffuse_color(t_objects *obj, t_vec light_p0,
		t_vec normal_obj, t_vec inters_point);
void				ft_specular_color(t_objects *obj, t_vec light_p0,
		t_vec normal_obj, t_vec inters_point);
int					ft_key(int keycode, t_objects *obj);
int					ft_mouse_move(int x, int y, t_objects *obj);
t_color				ft_final_color(t_objects *obj, t_list *head,
		t_vec inter_point);
t_color				ft_color_of_pixel(t_objects *obj, int specular_on_off);
void				ft_free_split(char **tmp, char *line);
void				ft_free_all(t_objects *obj);
void				ft_free_list(t_objects *obj);
double				ft_intersec_poly(t_list *list, t_vec ray_dir,
		t_vec ray_p0);
void				ft_chek_sphere(t_objects *obj, t_list *list, int i);
void				ft_chek_cone(t_objects *obj, t_list *list, int i);
void				ft_chek_cyl(t_objects *obj, t_list *list, int i);
void				ft_chek_plane(t_objects *obj, t_list *list, int i);
void				ft_chek_poly(t_objects *obj, t_list *list, int i);
t_list				*ft_create_elem(void *object, int id);
void				ft_add_object(t_list **head, void *object, int id);
void				ft_read(t_objects *obj);
int					ft_read_sphere(t_objects *obj, char **tmp);
int					ft_read_cone(t_objects *obj, char **tmp);
int					ft_read_cyl(t_objects *obj, char **tmp);
int					ft_read_plane(t_objects *obj, char **tmp);
int					ft_read_poly(t_objects *obj, char **tmp);
int					ft_read_light_ray(t_objects *obj, char **tmp);
t_color				ft_color_to_arr(int color_int);
t_color				ft_color_coeff(double coeff, t_color color);
t_color				ft_color_add(t_color c1, t_color c2);
t_color				ft_color_mult(t_color c1, t_color c2);
t_color				ft_color_make(int r, int g, int b);
int					ft_mouse(int button, int x, int y, t_objects *obj);
void				ft_key_rotate(int keycode, t_objects *obj);
void				ft_put_pixel(t_mlx *m, int x, int y, t_color col);
t_vec				ft_vector_sub(t_vec v1, t_vec v2);
t_vec				ft_vector_add(t_vec v1, t_vec v2);
double				ft_vector_scal_prod(t_vec v1, t_vec v2);
double				ft_vector_modul(t_vec v1, t_vec v2);
t_vec				ft_vector_cross_prod(t_vec v1, t_vec v2);
t_vec				ft_vector_unit(t_vec v);
t_vec				ft_vector_mult(t_vec v1, double nb);
double				ft_max(double nb1, double nb2);
t_vec				ft_vector(double x, double y, double z, double w);
double				ft_vector_mult_vector(t_vec v1, t_vec v2);
t_vec				ft_rotate(t_vec v, t_objects *obj, char axis);
void				ft_rotate_objects(t_objects *obj, char axis);
#endif
