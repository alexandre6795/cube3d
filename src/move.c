/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:06:14 by aherrman          #+#    #+#             */
/*   Updated: 2024/01/04 15:34:56 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	ft_moveup(t_cube *cube)
{
	float	addxy[2];

	if (calc_dist_before_hit(cube, 0) == 1)
		return ;
	addxy[0] = cosf(cube->player->angle) * 5;
	addxy[1] = sinf(cube->player->angle) * 5;
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
	addxy[0] = cosf(cube->player->angle) * 5;
	addxy[1] = sinf(cube->player->angle) * 5;
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
	addxy[0] = cosf(cube->player->angle - convert_deg_pirad(90)) * 5;
	addxy[1] = sinf(cube->player->angle - convert_deg_pirad(90)) * 5;
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
	addxy[0] = cosf(cube->player->angle - convert_deg_pirad(90)) * 5;
	addxy[1] = sinf(cube->player->angle - convert_deg_pirad(90)) * 5;
	cube->player->y -= addxy[1];
	cube->player->x -= addxy[0];
	cube->texture->circle->instances[0].x = cube->player->x/ 4 - 4;
	cube->texture->circle->instances[0].y = cube->player->y / 4 - 4;
}
