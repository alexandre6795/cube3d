/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:19:19 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/18 13:16:37 by aherrman         ###   ########.fr       */
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
	cube->texture->green = mlx_new_image(cube->mlx, cube->map->size_y * 64,
			cube->map->size_x * 64);
	while (i < cube->map->size_x * 64)
	{
		j = 0;
		while (j < cube->map->size_y * 64)
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
				cube->player->angle = 90;
			else if (cube->map->map[i][j] == 'E')
				cube->player->angle = 0;
			else if (cube->map->map[i][j] == 'S')
				cube->player->angle = 270;
			else if (cube->map->map[i][j] == 'W')
				cube->player->angle = 180;
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
	mlx_image_to_window(cube->mlx, cube->texture->green, 0, 0);
}

void	create_world(t_cube *cube)
{
	create_image(cube);
	create_person(cube);
	image_to_map(cube);
}