/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_world.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:26:10 by akastler          #+#    #+#             */
/*   Updated: 2024/01/05 10:24:53 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	get_color(t_cube *cube, int ray_nbr, int actual_height)
{
	(void)actual_height;
	if (cube->player->ray[ray_nbr].hitted == 1)
		return (rgba(255, 0, 0, 255));
	else if (cube->player->ray[ray_nbr].hitted == 2)
		return (rgba(0, 255, 0, 255));
	else if (cube->player->ray[ray_nbr].hitted == 3)
		return (rgba(0, 0, 255, 255));
	else if (cube->player->ray[ray_nbr].hitted == 4)
		return (rgba(255, 255, 255, 255));
	return (rgba(0, 0, 0, 255));
}

void	draw_3d(t_cube *cube, int ray_nbr)
{
	int     i;
	int     color;
	float   dist;

	i = 0;
    cube->player->ray[ray_nbr].dist = cube->player->ray[ray_nbr].dist * cos(cube->player->ray[ray_nbr].angle - cube->player->angle);
	dist = (HEIGHT * 64) / cube->player->ray[ray_nbr].dist;
	while (i < HEIGHT)
	{
		if (i < (HEIGHT - dist) / 2)
			color = rgba(cube->texture->sky[0], cube->texture->sky[1], cube->texture->sky[0], 255);
		else if (i > (HEIGHT + dist) / 2)
			color = rgba(cube->texture->floor[0],cube->texture->floor[1],cube->texture->floor[2],255);
		else
			color = get_color(cube, ray_nbr, i);
		mlx_put_pixel(cube->texture->rendu, ray_nbr, i, color);
		i++;
	}
}
