/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:19:19 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/14 12:48:40 by aherrman         ###   ########.fr       */
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
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			mlx_put_pixel(cube->texture->black, i, j, int_rgb_to_hex_rgb(0, 0,
					0, 255));
			mlx_put_pixel(cube->texture->white, i, j, int_rgb_to_hex_rgb(222,
					222, 222, 100));
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