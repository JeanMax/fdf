/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 16:18:20 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/15 09:36:35 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** lis une map et et remplie une liste de maillons (x, y, z)
*/

#include "header.h"

static void		check_map(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '-' || s[i] == '\n')
		i++;
	s += i;
	if (!ft_atoi(s) && s[i] != '0')
		EXIT_MAP_FAIL;
	s -= i;
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '-' && s[i] != '\n')
			EXIT_MAP_FAIL;
		i++;
	}
}

static void		fill_list(char *line, int y, t_env *e)
{
	int	x;
	int	z;
	int	start;

	start = 0;
	x = 0;
	while (line[start] && line[start] != '\n')
	{
		if (ft_isdigit(line[start]) || line[start] == '-')
		{
			z = ft_atoi(line + start);
			if (e->first_l == NULL)
				e->first_l = ft_lnew(x++, y, z);
			else
				ft_ladd(&(e->first_l), ft_lnew(x++, y, z));
			while (ft_isdigit(line[start]) || line[start] == '-')
				start++;
			e->coord_max = z > e->coord_max ? z : e->coord_max;
			e->z_max = z > e->z_max ? z : e->z_max;
			e->z_min = z < e->z_min ? z : e->z_min;
		}
		else
			start++;
	}
	e->coord_max = x > e->coord_max ? x : e->coord_max;
}

void			read_map(t_env *e)
{
	int		i;
	int		y;
	char	*buf;
	char	*a;

	a = (char *)malloc(sizeof(char));
	buf = (char *)malloc(sizeof(char) * 128);
	while ((i = read(e->fd, buf, 128)) > 0)
	{
		buf[i] = '\0';
		a = (char *)ft_realloc((void *)a, ft_strlen(a), ft_strlen(a) + i);
		ft_strcat(a, buf);
	}
	i = 0;
	y = 0;
	check_map(a);
	fill_list(a, y, e);
	while (a[i])
	{
		a[i] == '\n' ? fill_list(a + i + 1, ++y, e) : 0;
		i++;
	}
	e->coord_max = y > e->coord_max ? y : e->coord_max;
	free(a);
	free(buf);
}
