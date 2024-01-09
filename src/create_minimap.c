/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:23:25 by aherrman          #+#    #+#             */
/*   Updated: 2024/01/09 08:37:30 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	create_i(t_cube *cube, int imax, int jmax, int i)
{
	int	j;

	j = 0;
	while (i < imax)
	{
		j = 0;
		while (j < jmax)
		{
			if (i < 16 && j < 16)
			{
				mlx_put_pixel(cube->texture->black, i, j, rgba(0, 0, 0, 255));
				mlx_put_pixel(cube->texture->white, i, j, rgba(222, 222, 222,
						255));
			}
			j++;
		}
		i++;
	}
}

void	create_minimap(t_cube *cube)
{
	cube->texture->black = mlx_new_image(cube->mlx, 16, 16);
	cube->texture->white = mlx_new_image(cube->mlx, 16, 16);
	cube->texture->green = mlx_new_image(cube->mlx, cube->map->size_y * 16,
			cube->map->size_x * 16);
	create_i(cube, cube->map->size_x * 16, cube->map->size_y * 16, 0);
}
