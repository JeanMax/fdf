/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:46:33 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/08 06:19:17 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ceci est un main!
*/

#include "header.h"

void	calc_coord(t_env *e)
{
	t_lst	*tmp;
	double	angle;

	tmp = e->first_l;
	while (tmp)
	{
		angle = M_PI / 180 * e->angle;
		tmp->x_pix = tmp->x * (e->win_size / e->coord_max * 0.63) * e->zoom;
		tmp->y_pix = tmp->y * (e->win_size / e->coord_max * 0.63) * e->zoom;
		tmp->x_pix += cos(angle) * e->cste * tmp->z * e->zoom;
		tmp->y_pix += sin(angle) * e->cste * tmp->z * e->zoom;
		angle = M_PI / 180 * e->win_ang;
		tmp->x_pix = tmp->x_pix * cos(angle) + tmp->y_pix * sin(angle);
		tmp->y_pix = tmp->y_pix * cos(angle) - tmp->x_pix * sin(angle);
		tmp->x_pix += e->win_size / 3 + e->move_x;
		tmp->y_pix += e->win_size / 3.5 + e->move_y;
		tmp = tmp->next;
	}
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		EXIT_ARG_FAIL;
	if ((e.fd = open(av[1], O_RDONLY)) < 0)
        EXIT_NO_MAP;
	e.first_l = NULL;
	e.win_size = 1000;
	e.win_ang = -30;
	e.cste = 1.5;
	e.angle = -140;
	e.coord_max = 0;
	e.zoom = 1;
	e.move_x = 0;
	e.move_y = 0;
	e.box = 'a';
	read_map(&e);
	close(e.fd);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.win_size, e.win_size, "zboub");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
