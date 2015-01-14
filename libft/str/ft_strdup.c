/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:11:19 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/09 21:20:13 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strdup() function returns a pointer to a  new  string  which  is  a
** duplicate  of the string s.  Memory for the new string is obtained with
** malloc(3), and can be freed with free(3).
*/

#include "libft.h"
#include <stdlib.h>

char *ft_strdup(char *src)
{
	unsigned int		i;
	char				*dup;

	i = 1;
	if (!src)
		return (NULL);
	while (src[i])
		i++;
	dup = malloc(sizeof(char) * i);
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
