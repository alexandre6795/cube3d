/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:23:25 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/19 09:30:55 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	create_i(t_cube *cube, int imax, int jmax, int i, int j)
{
	while (i < imax)
	{
		j = 0;
		while (j < jmax)
		{
			if (i < 64 && j < 64)
			{
				mlx_put_pixel(cube->texture->black, i, j, rgba(0, 0, 0, 255));
				mlx_put_pixel(cube->texture->white, i, j, rgba(222, 222, 222,
						100));
			}
			if (i < 32 && j < 32)
				mlx_put_pixel(cube->texture->red, i, j, rgba(222, 0, 0, 100));
			j++;
		}
		i++;
	}
}

void	create_minimap(t_cube *cube)
{
	cube->texture->black = mlx_new_image(cube->mlx, 64, 64);
	cube->texture->white = mlx_new_image(cube->mlx, 64, 64);
	cube->texture->red = mlx_new_image(cube->mlx, 32, 32);
	cube->texture->green = mlx_new_image(cube->mlx, cube->map->size_y * 64,
			cube->map->size_x * 64);
	create_i(cube, cube->map->size_x * 64, cube->map->size_y * 64, 0, 0);
}
