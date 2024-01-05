/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:52:07 by aherrman          #+#    #+#             */
/*   Updated: 2024/01/04 15:43:57 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	default_ray(t_cube *cube)
{
	int		i;
	float	decal;

	i = 0;
	decal = convert_deg_pirad((float)cube->player->fov / (float)NB_RAY);
	while (i < NB_RAY)
	{
		cube->player->ray[i].x = cube->player->x;
		cube->player->ray[i].y = cube->player->y;
		cube->player->ray[i].dist = 0;
		if (i == 0)
			cube->player->ray[i].angle = cube->player->angle
				- convert_deg_pirad(cube->player->fov / 2);
		else
			cube->player->ray[i].angle
				= cube->player->ray[i - 1].angle + decal;
		if (cube->player->ray[i].angle > 2 * PI)
			cube->player->ray[i].angle -= 2 * PI;
		else if (cube->player->ray[i].angle < 0)
			cube->player->ray[i].angle += 2 * PI;
		i++;
	}
}

void	reset_image_ray(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cube->map->size_x * 16)
	{
		j = 0;
		while (j < cube->map->size_y * 16)
		{
			mlx_put_pixel(cube->texture->green, j, i, rgba(0, 0, 0, 0));
			j++;
		}
		i++;
	}
}
