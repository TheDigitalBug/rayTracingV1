# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 10:15:44 by kkotliar          #+#    #+#              #
#    Updated: 2017/05/15 09:38:13 by kkotliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

CC = gcc

CFLAG = -Wall -Werror -Wextra -framework OpenGL -framework AppKit


OBJ = ft_read.o \
	  rtv1.o \
	  ft_put_pixel.o \
	  ft_vector.o \
	  ft_vector_2.o \
	  ft_intersection_point.o \
	  ft_sphere.o \
	  ft_max.o \
	  ft_color.o \
	  ft_final_color.o \
	  ft_cone.o \
	  ft_cylinder.o \
	  ft_plane.o \
	  ft_key.o \
	  ft_free.o \
	  ft_rotate_scene.o \
	  ft_polygon.o \
	  ft_check_pixel.o \
	  ft_add_object.o \
	  ft_create_elem.o \
	  ft_read_sphere.o \
	  ft_read_cyl.o \
	  ft_read_plane.o \
	  ft_read_poly.o \
	  ft_read_light_ray.o \
	  ft_read_cone.o

HEADER = rtv1.h

LIB = libft/libft.a
LIBM = minilibx/libmlx.a

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	make -C minilibx
	$(CC)  $^ $(CFLAG) $(LIBM) $(LIB) -o $@

clean:
	make clean -C ./libft
	make clean -C ./minilibx
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
	make re -C ./libft
	make re -C ./minilibx