/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 01:18:58 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/08 05:53:24 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** create a box allowing to choose a color
*/

#include "header.h"

static void	draw_square(int x, int y, t_env *e)
{
	int		half;
	t_lst	*a;
	t_lst	*b;

	a = malloc(sizeof(t_lst));
	b = malloc(sizeof(t_lst));
	a->z = 0;
	b->z = 0;
	half = 10;
	a->x_pix = x - half;
	a->y_pix = y - half;
	b->x_pix = x - half;
	b->y_pix = y + half;
	draw_line(a, b, e);
	b->x_pix = x + half;
	b->y_pix = y - half;
	draw_line(a, b, e);
	a->x_pix = x + half;
	a->y_pix = y + half;
	draw_line(a, b, e);
	b->x_pix = x - half;
	b->y_pix = y + half;
	draw_line(a, b, e);
	free(a);
	free(b);
}

static void	tick_box(t_env *e, int mid_y)
{
	t_lst	*a;
	t_lst	*b;

	a = malloc(sizeof(t_lst));
	b = malloc(sizeof(t_lst));
	a->z = 0;
	b->z = 0;
	a->x_pix = 40;
	a->y_pix = mid_y + 10;
	b->x_pix = 20;
	b->y_pix = mid_y - 10;
	draw_line(a, b, e);
	a->x_pix = 20;
	a->y_pix = mid_y + 10;
	b->x_pix = 40;
	b->y_pix = mid_y - 10;
	draw_line(a, b, e);
	free(a);
	free(b);
}

static int	pick_some_more(int layer, char box)
{
	int	color;

	color = 0;
	if (layer == 4)
	{
		color = box == 'a' ? 3368499 : color;
		color = box == 'b' ? 0x33FF00 : color;
		color = box == 'c' ? 0x00FF00 : color;
	}
	else if (layer == 5)
	{
		color = box == 'a' ? 15195750 : color;
		color = box == 'b' ? 26367 : color;
		color = box == 'c' ? 0xFF0000 : color;
	}
	else if (layer == 6)
	{
		color = box == 'a' ? 26367 : color;
		color = box == 'b' ? 0x9900CC : color;
		color = box == 'c' ? 0xFF0000 : color;
	}
	return (color);
}

int			pick_color(int layer, char box)
{
	int	color;

	color = 0;
	if (layer == 1)
	{
		color = box == 'a' ? 16514043 : color;
		color = box == 'b' ? 0xFF0000 : color;
		color = box == 'c' ? 0x0000FF : color;
	}
	else if (layer == 2)
	{
		color = box == 'a' ? 7500402 : color;
		color = box == 'b' ? 0xE55E31 : color;
		color = box == 'c' ? 0x0000FF : color;
	}
	else if (layer == 3)
	{
		color = box == 'a' ? 6697728 : color;
		color = box == 'b' ? 0xFFFF00 : color;
		color = box == 'c' ? 0x00FF00 : color;
	}
	else if (layer > 3)
		color = pick_some_more(layer, box);
	return (color);
}

void		draw_box(t_env *e)
{
	char	str1[50];
	char	str2[50];
	char	str3[50];

	ft_strcpy(str1, "blue / yellow / green / brown / grey / white");
	ft_strcpy(str2, "purple / blue / green / yellow / orange / red");
	ft_strcpy(str3, "red / red / green / green / blue / blue");
	draw_square(30, 40, e);
	mlx_string_put(e->mlx, e->win, 50, 45, 16514043, str1);
	draw_square(30, 80, e);
	mlx_string_put(e->mlx, e->win, 50, 85, 16514043, str2);
	draw_square(30, 120, e);
	mlx_string_put(e->mlx, e->win, 50, 125, 16514043, str3);
	if (e->box == 'a')
		tick_box(e, 40);
	else if (e->box == 'b')
		tick_box(e, 80);
	else if (e->box == 'c')
		tick_box(e, 120);
}
