/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 17:28:24 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/08 06:24:09 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** hooks et plus si affinité
*/

#include "header.h"

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int		key_hook(int key, t_env *e)
{
	if (key == 65307)
		exit(0);
	else if (key == 65363)
		e->angle += 10;
	else if (key == 65361)
		e->angle -= 10;
	else if (key == 65362)
		e->cste += 0.1;
	else if (key == 65364)
		e->cste -= 0.1;
	else if (key == 65451)
        e->zoom += 0.1;
    else if (key == 65453 && e->zoom > 0.1)
        e->zoom -= 0.1;
	else if (key == 122)
        e->move_y -= 10;
    else if (key == 113)
        e->move_x -= 10;
    else if (key == 115)
        e->move_y += 10;
    else if (key == 100)
        e->move_x += 10;
	mlx_clear_window(e->mlx, e->win);
	draw(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	button = button;
	if (x >= 20 && x <= 40 && y >= 30 && y <= 50)
		e->box = 'a';
	else if (x >= 20 && x <= 40 && y >= 70 && y <= 90)
		e->box = 'b';
	else if (x >= 20 && x <= 40 && y >= 110 && y <= 130)
		e->box = 'c';
	mlx_clear_window(e->mlx, e->win);
	draw(e);
	return (0);
}
