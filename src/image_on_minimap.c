/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_on_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:36:03 by aherrman          #+#    #+#             */
/*   Updated: 2024/01/04 17:14:53 by aherrman         ###   ########.fr       */
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

void	image_to_map(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cube->map->map[i])
	{
		j = 0;
		while (cube->map->map[i][j] && j < cube->map->size_y)
		{
			// if (cube->map->map[i][j] == '1')
			// 	mlx_image_to_window(cube->mlx, cube->texture->black, j * 64, i
			// 		* 64);
			// else if (cube->map->map[i][j] == '0')
			// 	mlx_image_to_window(cube->mlx, cube->texture->white, j * 64, i
			// 		* 64);
			if (cube->map->map[i][j] == '0' || cube->map->map[i][j] == 'N'
				|| cube->map->map[i][j] == 'S' || cube->map->map[i][j] == 'E'
				|| cube->map->map[i][j] == 'W')
				mlx_image_to_window(cube->mlx, cube->texture->white, j * 16, i
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
