/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_memmory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:05:12 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/15 12:31:27 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_free_split(char **tmp, char *line)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	free(line);
}

void		ft_free_list(t_objects *obj)
{
	t_list *list;
	t_list *bufnext;

	list = obj->head;
	while (list)
	{
		if (list->id == 0 && list->sph)
			free(list->sph);
		else if (list->id == 1 && list->cone)
			free(list->cone);
		else if (list->id == 2 && list->cyl)
			free(list->cyl);
		else if (list->id == 3 && list->plane)
			free(list->plane);
		else if (list->id == 4 && list->poly)
			free(list->poly);
		bufnext = list->next;
		free(list);
		list = bufnext;
	}
	obj->head = NULL;
	obj->ray = NULL;
	obj->light = NULL;
}

void		ft_free_all(t_objects *obj)
{
	ft_free_list(obj);
	free(obj);
}
