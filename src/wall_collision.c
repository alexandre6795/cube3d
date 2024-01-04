/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:12:04 by akastler          #+#    #+#             */
/*   Updated: 2023/12/28 16:16:20 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

float	*wall_collision_vert(t_cube *cube, t_ray ray)
{
	float	*actualxy;
	float	tang;
	float	incrementxy[2];

	actualxy = malloc(sizeof(float) * 2);
	tang = -tanf(ray.angle);
	incrementxy[0] = 64;
	actualxy[0] = ((int)(ray.x / 64)*64) + 64;
	if (ray.angle > (PI / 2) && ray.angle < (3 * PI / 2))
	{
		incrementxy[0] = -64;
		actualxy[0] = ((int)(ray.x / 64)*64) - 0.0002;
	}
	actualxy[1] = (ray.x - actualxy[0]) * tang + ray.y;
	incrementxy[1] = -incrementxy[0] * tang;
	while (actualxy[0] >= 0 && actualxy[1] >= 0
		&& actualxy[0] < cube->map->size_y * 64
		&& actualxy[1] < cube->map->size_x * 64)
	{
		if (cube->map->map[(int)actualxy[1] / 64][(int)actualxy[0] / 64] == '1')
			break ;
		actualxy[0] += incrementxy[0];
		actualxy[1] += incrementxy[1];
	}
	return (actualxy);
}

float	*wall_collision_hori(t_cube *cube, t_ray ray)
{
	float	*actualxy;
	float	tang;
	float	incrementxy[2];

	actualxy = malloc(sizeof(float) * 2);
	tang = -1.0f / tanf(ray.angle);
	incrementxy[1] = 64;
	actualxy[1] = ((int)(ray.y / 64)*64) + 64;
	if (ray.angle > PI)
	{
		incrementxy[1] = -64;
		actualxy[1] = ((int)(ray.y / 64)*64) - 0.0002;
	}
	actualxy[0] = (ray.y - actualxy[1]) * tang + ray.x;
	incrementxy[0] = -incrementxy[1] * tang;
	while (actualxy[0] >= 0 && actualxy[1] >= 0
		&& actualxy[0] < cube->map->size_y * 64
		&& actualxy[1] < cube->map->size_x * 64)
	{
		if (cube->map->map[(int)actualxy[1] / 64][(int)actualxy[0] / 64] == '1')
			break ;
		actualxy[0] += incrementxy[0];
		actualxy[1] += incrementxy[1];
	}
	return (actualxy);
}
