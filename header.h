/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/08 06:16:15 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H
# define EXIT_MAP_FAIL { ft_putendl("Map is not valid."); exit(0); }
# define EXIT_NO_MAP { ft_putendl("Map not found."); exit(0); }
# define EXIT_ARG_FAIL { ft_putendl("Two arguments needed."); exit(0); }

# include "libft/inc/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_env	t_env;
struct	s_env
{
	void	*mlx;
	void	*win;
	int		win_size;
	t_lst	*first_l;
	int		fd;
	double	cste;
	int		angle;
	int		coord_max;
	int		win_ang;
	int		z_max;
	int		z_min;
	double	zoom;
	double	move_x;
	double	move_y;
	char	box;
};

int		key_hook(int key, t_env *e);
int		mouse_hook(int button, int x, int y, t_env *e);
int		expose_hook(t_env *e);
int		pick_color(int layer, char box);
void	draw(t_env *e);
void	draw_line(t_lst *a, t_lst *b, t_env *e);
void	read_map(t_env *e);
void	calc_coord(t_env *e);
void	draw_box(t_env *e);

#endif
