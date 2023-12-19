/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_on_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:36:03 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/19 09:36:49 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	image_to_map(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cube->map->map[i])
	{
		j = 0;
		while (cube->map->map[i][j])
		{
			if (cube->map->map[i][j] == '1')
				mlx_image_to_window(cube->mlx, cube->texture->black, j * 64, i
					* 64);
			else if (cube->map->map[i][j] == '0')
				mlx_image_to_window(cube->mlx, cube->texture->white, j * 64, i
					* 64);
			j++;
		}
		i++;
	}
	mlx_image_to_window(cube->mlx, cube->texture->green, 0, 0);
}