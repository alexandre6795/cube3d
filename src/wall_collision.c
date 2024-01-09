/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:12:04 by akastler          #+#    #+#             */
/*   Updated: 2024/01/09 11:32:37 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"


void	init_raycast(t_raycast *rayc, int setting, t_ray ray)
{
	rayc->actxy = malloc(sizeof(float) * 2);
	rayc->tang = -tanf(ray.angle);
	rayc->incrementxy[0] = 64;
	rayc->actxy[0] = ((int)(ray.x / 64)*64) + 64;
	if (ray.angle > (PI / 2) && ray.angle < (3 * PI / 2))
	{
		rayc->incrementxy[0] = -64;
		rayc->actxy[0] = ((int)(ray.x / 64)*64) - 0.0002;
	}
	rayc->actxy[1] = (ray.x - rayc->actxy[0]) * rayc->tang + ray.y;
	rayc->incrementxy[1] = -rayc->incrementxy[0] * rayc->tang;
	if (setting == 1)
	{
		rayc->tang = -1.0f / tanf(ray.angle);
		rayc->incrementxy[1] = 64;
		rayc->actxy[1] = ((int)(ray.y / 64)*64) + 64;
		if (ray.angle > PI)
		{
			rayc->incrementxy[1] = -64;
			rayc->actxy[1] = ((int)(ray.y / 64)*64) - 0.0002;
		}
		rayc->actxy[0] = (ray.y - rayc->actxy[1]) * rayc->tang + ray.x;
		rayc->incrementxy[0] = -rayc->incrementxy[1] * rayc->tang;
	}
}

float	*wall_collision_vert(t_cube *cube, t_ray *ray)
{
	t_raycast	rc;

	init_raycast(&rc, 0, *ray);
	while (rc.actxy[0] >= 0 && rc.actxy[1] >= 0
		&& rc.actxy[0] < cube->map->size_y * 64
		&& rc.actxy[1] < cube->map->size_x * 64)
	{
		if (cube->map->map[(int)rc.actxy[1] / 64][(int)rc.actxy[0] / 64] == '1'
			|| cube->map->map[(int)rc.actxy[1] / 64][(int)rc.actxy[0] / 64] == 'D'
			|| cube->map->map[(int)rc.actxy[1] / 64][(int)rc.actxy[0] / 64] == 'O')
		{
			ray->block_type[0] = cube->map->map[(int)rc.actxy[1] / 64][(int)rc.actxy[0] / 64];
			break ;
		}
		rc.actxy[0] += rc.incrementxy[0];
		rc.actxy[1] += rc.incrementxy[1];
	}
	return (rc.actxy);
}

float	*wall_collision_hori(t_cube *cube, t_ray *ray)
{
	t_raycast	rc;

	init_raycast(&rc, 1, *ray);
	while (rc.actxy[0] >= 0 && rc.actxy[1] >= 0
		&& rc.actxy[0] < cube->map->size_y * 64
		&& rc.actxy[1] < cube->map->size_x * 64)
	{
		if (cube->map->map[(int)rc.actxy[1] / 64][(int)rc.actxy[0] / 64] == '1'
			|| cube->map->map[(int)rc.actxy[1] / 64][(int)rc.actxy[0] / 64] == 'D'
			|| cube->map->map[(int)rc.actxy[1] / 64][(int)rc.actxy[0] / 64] == 'O')
		{
			ray->block_type[1] = cube->map->map[(int)rc.actxy[1] / 64][(int)rc.actxy[0] / 64];
			break ;
		}
		rc.actxy[0] += rc.incrementxy[0];
		rc.actxy[1] += rc.incrementxy[1];
	}
	return (rc.actxy);
}
