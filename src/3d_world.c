/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_world.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:26:10 by akastler          #+#    #+#             */
/*   Updated: 2024/01/09 10:33:05 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	get_color(t_cube *cube, int ray_nbr, t_wall *wall)
{
	// if (cube->player->ray[ray_nbr].block_type != '1')
	// change the texture var
	if (cube->player->ray[ray_nbr].hitted == 1
		|| cube->player->ray[ray_nbr].hitted == 3)
	{
		wall->value
			= (((int)(cube->player->ray[ray_nbr].x / (64 / wall->texture->height)) % wall->texture->height)
				+ ((int)wall->current * wall->texture->height)) * 4;
	}
	else
	{
		wall->value
			= (((int)(cube->player->ray[ray_nbr].y / (64 / wall->texture->height)) % wall->texture->height)
				+ ((int)wall->current * wall->texture->height)) * 4;
	}
	wall->color = rgba(wall->texture->pixels[wall->value],
			wall->texture->pixels[wall->value + 1],
			wall->texture->pixels[wall->value + 2],
			wall->texture->pixels[wall->value + 3]);
	wall->current += wall->step;
	return (wall->color);
}

void	set_all_wall(t_wall *wall, t_cube *cube, int ray_nbr)
{
	wall->fisheyes = cube->player->angle - cube->player->ray[ray_nbr].angle;
	if (wall->fisheyes > PI)
		wall->fisheyes -= 2 * PI;
	else if (wall->fisheyes < 0)
		wall->fisheyes += 2 * PI;
	if (cube->player->ray[ray_nbr].hitted == 1)
		wall->texture = cube->texture->nord;
	else if (cube->player->ray[ray_nbr].hitted == 2)
		wall->texture = cube->texture->est;
	else if (cube->player->ray[ray_nbr].hitted == 3)
		wall->texture = cube->texture->south;
	else if (cube->player->ray[ray_nbr].hitted == 4)
		wall->texture = cube->texture->west;
	wall->dist = cube->player->ray[ray_nbr].dist * cos(wall->fisheyes);
	wall->height = (HEIGHT * 64) / wall->dist;
	wall->color = 0;
	wall->step = (float)wall->texture->height / (float)wall->height;
	wall->current = 0.0f;
	wall->wall = (HEIGHT + wall->height) / 2;
	if (wall->wall > HEIGHT)
	{
		wall->current = (wall->height - HEIGHT) / 2.0;
		wall->wall = HEIGHT;
	}
	wall->current *= wall->step;
}

void	draw_3d(t_cube *cube, int ray_nbr)
{
	int		i;
	int		color;
	t_wall	wall;

	i = 0;
	set_all_wall(&wall, cube, ray_nbr);
	while (i < HEIGHT)
	{
		if (i < (HEIGHT - wall.height) / 2)
			color = rgba(cube->texture->sky[0],
					cube->texture->sky[1], cube->texture->sky[0], 255);
		else if (i > (HEIGHT + wall.height) / 2)
			color = rgba(cube->texture->floor[0],
					cube->texture->floor[1], cube->texture->floor[2], 255);
		else
			color = get_color(cube, ray_nbr, &wall);
		mlx_put_pixel(cube->texture->rendu, ray_nbr, i, color);
		i++;
	}
}
