/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:06:14 by aherrman          #+#    #+#             */
/*   Updated: 2024/01/10 13:44:07 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	ft_moveup(t_cube *cube)
{
	float	addxy[2];

	if (calc_dist_before_hit(cube, 0) == 1)
		return ;
	addxy[0] = cosf(cube->player->angle) * PLAYER_SPEED;
	addxy[1] = sinf(cube->player->angle) * PLAYER_SPEED;
	cube->player->y += addxy[1];
	cube->player->x += addxy[0];
	cube->texture->circle->instances[0].y = cube->player->y / 4 - 4;
	cube->texture->circle->instances[0].x = cube->player->x / 4 - 4;
}

void	ft_movedown(t_cube *cube)
{
	float	addxy[2];

	if (calc_dist_before_hit(cube, 3) == 1)
		return ;
	addxy[0] = cosf(cube->player->angle) * PLAYER_SPEED;
	addxy[1] = sinf(cube->player->angle) * PLAYER_SPEED;
	cube->player->y -= addxy[1];
	cube->player->x -= addxy[0];
	cube->texture->circle->instances[0].y = cube->player->y / 4 - 4;
	cube->texture->circle->instances[0].x = cube->player->x / 4 - 4;
}

void	ft_moveleft(t_cube *cube)
{
	float	addxy[2];

	if (calc_dist_before_hit(cube, 2) == 1)
		return ;
	addxy[0] = cosf(cube->player->angle - convert_deg_pirad(90)) * PLAYER_SPEED;
	addxy[1] = sinf(cube->player->angle - convert_deg_pirad(90)) * PLAYER_SPEED;
	cube->player->y += addxy[1];
	cube->player->x += addxy[0];
	cube->texture->circle->instances[0].x = cube->player->x / 4 - 4;
	cube->texture->circle->instances[0].y = cube->player->y / 4 - 4;
}

void	ft_moveright(t_cube *cube)
{
	float	addxy[2];

	if (calc_dist_before_hit(cube, 1) == 1)
		return ;
	addxy[0] = cosf(cube->player->angle - convert_deg_pirad(90)) * PLAYER_SPEED;
	addxy[1] = sinf(cube->player->angle - convert_deg_pirad(90)) * PLAYER_SPEED;
	cube->player->y -= addxy[1];
	cube->player->x -= addxy[0];
	cube->texture->circle->instances[0].x = cube->player->x / 4 - 4;
	cube->texture->circle->instances[0].y = cube->player->y / 4 - 4;
}

void	hodor(t_cube *cube)
{
	if (cube->player->ray[NB_RAY / 2].block_type[0] == 'D'
		&& cube->player->ray[NB_RAY / 2].dist <= 50)
	{
		cube->map->map[(int)cube->player->ray[NB_RAY / 2].y
			/ 64][(int)cube->player->ray[NB_RAY / 2].x / 64] = 'O';
	}
	else if (cube->player->ray[NB_RAY / 2].block_type[0] == 'O'
		&& cube->player->ray[NB_RAY / 2].dist <= 500)
	{
		cube->map->map[(int)cube->player->ray[NB_RAY / 2].y
			/ 64][(int)cube->player->ray[NB_RAY / 2].x / 64] = 'D';
	}
}
