/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:54:56 by akastler          #+#    #+#             */
/*   Updated: 2024/01/09 12:12:11 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

t_ray	ray_for_dir(t_cube *cube, int direction)
{
	t_ray	ray;

	ray.x = cube->player->x;
	ray.y = cube->player->y;
	ray.angle = cube->player->angle;
	if (direction == 1)
		ray.angle = cube->player->angle + convert_deg_pirad(90);
	else if (direction == 2)
		ray.angle = cube->player->angle - convert_deg_pirad(90);
	else if (direction == 3)
		ray.angle = cube->player->angle + convert_deg_pirad(180);
	if (ray.angle > 2 * PI)
		ray.angle -= 2 * PI;
	if (ray.angle < 0)
		ray.angle += 2 * PI;
	return (ray);
}

int	calc_dist_before_hit(t_cube *cube, int direction)
{
	float	*stop;
	float	*stop2;
	float	wall_hit_dist_hv[2];
	t_ray	ray;

	ray = ray_for_dir(cube, direction);
	stop = wall_collision_vert(cube, &ray);
	stop2 = wall_collision_hori(cube, &ray);
	wall_hit_dist_hv[1] = sqrtf(powf(cube->player->x - stop[0], 2)
			+ powf(cube->player->y - stop[1], 2));
	wall_hit_dist_hv[0] = sqrtf(powf((cube->player->x) - stop2[0], 2)
			+ powf((cube->player->y) - stop2[1], 2));
	if (wall_hit_dist_hv[1] > wall_hit_dist_hv[0])
		wall_hit_dist_hv[1] = wall_hit_dist_hv[0];
	free(stop2);
	free(stop);
	if ((wall_hit_dist_hv[1]) < 10 /*&& ray.block_type[0] == '1'*/)
		return (1);
	return (0);
}
