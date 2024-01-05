/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:03:14 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/12 09:15:50 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// only for test fonction

#include "../include/cube3d.h"
#include <stdlib.h>
#include <stdio.h>

void	print_map(t_cube *cube)
{
	int	i;

	i = 0;
	while (cube->map->map[i])
	{
		printf("%s\n", cube->map->map[i]);
		i++;
	}
	i++;
	i = 0;
	printf("\n");
	while (cube->texture->path[i])
	{
		printf("%s\n", cube->texture->path[i]);
		i++;
	}
}
