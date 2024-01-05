/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_world.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:26:10 by akastler          #+#    #+#             */
/*   Updated: 2024/01/05 12:43:12 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	get_color(t_cube *cube, int ray_nbr, t_wall *wall)
{
	wall->value = (((int)(cube->player->ray[ray_nbr].x) % wall->size)
		+ ((int)wall->current_step * wall->size)) * 4;
	wall->color = rgba(wall->texture->pixels[wall->value],
			wall->texture->pixels[wall->value + 1],
			wall->texture->pixels[wall->value + 2],
			wall->texture->pixels[wall->value + 3]);
	wall->current_step += wall->step;
	return (wall->color);
}

void	fonction(mlx_texture_t *texture, t_cube *cube, int ray_nbr,
		t_wall *wall)
{
	(void)cube;
	(void)ray_nbr;
	wall->hauteur = (HEIGHT * 64)
		/ wall->dist;
	wall->step = 64 / (float)(wall->hauteur);
	wall->wall = (HEIGHT * wall->hauteur) / 2;
	wall->size = 64;
	wall->texture = texture;
	if (wall->wall > HEIGHT)
	{
		wall->current_step = (wall->hauteur - HEIGHT) / 2.0;
		wall->wall = HEIGHT;
	}
	wall->current_step *= wall->step;
}

void	init_wall_with_dir(t_wall *wall, t_cube *cube, int ray_nbr)
{
	wall->color = 0;
	wall->current_step = 0.0f;
	if (cube->player->ray[ray_nbr].hitted == 1)
	{
		fonction(cube->texture->nord, cube, ray_nbr, wall);
	}
	else if (cube->player->ray[ray_nbr].hitted == 2)
	{
		fonction(cube->texture->est, cube, ray_nbr, wall);
	}
	else if (cube->player->ray[ray_nbr].hitted == 3)
	{
		fonction(cube->texture->south, cube, ray_nbr, wall);
	}
	else if (cube->player->ray[ray_nbr].hitted == 4)
	{
		fonction(cube->texture->west, cube, ray_nbr, wall);
	}
}


void	draw_3d(t_cube *cube, int ray_nbr)
{
	int		i;
	int		color;
	float	dist;
	t_wall	wall;
	float temp;

	i = 0;
	temp = cube->player->angle - cube->player->ray[ray_nbr].angle;
	if (temp > 2 * PI)
		temp -= 2 * PI;
	else if (temp < 0)
		temp += 2 * PI;
	dist = cube->player->ray[ray_nbr].dist * cosf(temp);
	wall.dist = dist;
	init_wall_with_dir(&wall, cube, ray_nbr);
	while (i < HEIGHT)
	{
		if (i < (HEIGHT - dist) / 2)
			color = rgba(cube->texture->sky[0], cube->texture->sky[1],
					cube->texture->sky[0], 255);
		else if (i > (HEIGHT + dist) / 2)
			color = rgba(cube->texture->floor[0], cube->texture->floor[1],
					cube->texture->floor[2], 255);
		else
			color = get_color(cube, ray_nbr, &wall);
		mlx_put_pixel(cube->texture->rendu, ray_nbr, i, color);
		i++;
	}
}
