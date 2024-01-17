/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_on_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:36:03 by aherrman          #+#    #+#             */
/*   Updated: 2024/01/17 12:20:03 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	complete_line(int i, int j, t_cube *cube)
{
	while (j < cube->map->size_y)
	{
		mlx_image_to_window(cube->mlx, cube->texture->black, j * 16, i * 16);
		j++;
	}
}

void	image_to_map(t_cube *cube, int i, int j)
{
	while (cube->map->map[i])
	{
		j = 0;
		while (cube->map->map[i][j] && j < cube->map->size_y)
		{
			if (cube->map->map[i][j] == '0' || cube->map->map[i][j] == 'N'
				|| cube->map->map[i][j] == 'S' || cube->map->map[i][j] == 'E'
				|| cube->map->map[i][j] == 'W')
				mlx_image_to_window(cube->mlx, cube->texture->white, j * 16, i
					* 16);
			else if (cube->map->map[i][j] == 'D')
				mlx_image_to_window(cube->mlx, cube->texture->doori, j * 16, i
					* 16);
			else
				mlx_image_to_window(cube->mlx, cube->texture->black, j * 16, i
					* 16);
			j++;
		}
		complete_line(i, j, cube);
		i++;
	}
	mlx_image_to_window(cube->mlx, cube->texture->green, 0, 0);
}
