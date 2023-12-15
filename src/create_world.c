/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:19:19 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/15 14:02:30 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	create_image(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	cube->texture->black = mlx_new_image(cube->mlx, 64, 64);
	cube->texture->white = mlx_new_image(cube->mlx, 64, 64);
	cube->texture->red = mlx_new_image(cube->mlx, 32, 32);
	cube->texture->green = mlx_new_image(cube->mlx, 8, 8);
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			mlx_put_pixel(cube->texture->black, i, j, int_rgb_to_hex_rgb(0, 0,
					0, 255));
			mlx_put_pixel(cube->texture->white, i, j, int_rgb_to_hex_rgb(222,
					222, 222, 100));
			if (i < 32 && j < 32)
				mlx_put_pixel(cube->texture->red, i, j, int_rgb_to_hex_rgb(222,
						0, 0, 100));
			if (i < 8 && j < 8)
				mlx_put_pixel(cube->texture->green, i, j, int_rgb_to_hex_rgb(0,
						222, 0, 100));
			j++;
		}
		i++;
	}
}

int	create_person(t_cube *cube)
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
			if (cube->map->map[i][j] == 'N' || cube->map->map[i][j] == 'S'
				|| cube->map->map[i][j] == 'E' || cube->map->map[i][j] == 'W')
				mlx_image_to_window(cube->mlx, cube->texture->red, j * 64 + 16,
					i * 64 + 16);
			if (cube->map->map[i][j] == 'N')
				mlx_image_to_window(cube->mlx, cube->texture->green, j * 64
					+ 28, i * 64 + 8);
			else if (cube->map->map[i][j] == 'E')
				mlx_image_to_window(cube->mlx, cube->texture->green, j * 64 + 8,
					i * 64 + 28);
			else if (cube->map->map[i][j] == 'S')
				mlx_image_to_window(cube->mlx, cube->texture->green, j * 64
					+ 28, i * 64 + 48);
			else if (cube->map->map[i][j] == 'W')
				mlx_image_to_window(cube->mlx, cube->texture->green, j * 64
					+ 48, i * 64 + 28);
			j++;
		}
		i++;
	}
	return (0);
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
}

void	create_world(t_cube *cube)
{
	create_image(cube);
	create_person(cube);
	image_to_map(cube);
}