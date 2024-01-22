/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:19:19 by aherrman          #+#    #+#             */
/*   Updated: 2024/01/22 14:06:00 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	create_circle(t_cube *cube)
{
	int	rayon;
	int	y;
	int	x;
	int	dist;

	rayon = 5;
	y = 0;
	x = 0;
	dist = 0;
	cube->texture->circle = mlx_new_image(cube->mlx, 8, 8);
	while (x < 8)
	{
		y = 0;
		while (y < 8)
		{
			dist = (x - 4) * (x - 4) + (y - 4) * (y - 4);
			if (dist < rayon * rayon)
				mlx_put_pixel(cube->texture->circle, x, y, rgba(0, 0, 255,
						255));
			y++;
		}
		x++;
	}
}

// void invert_image(mlx_texture_t *texture)
// {
// 	uint32_t i;
// 	uint32_t j;
// 	uint32_t tmp;

// 	i = 0;
// 	j = 0;
// 	while (i < texture->width * texture->height)
// 	{
// 		texture
// 		i++;
// 	}
// }

void	create_world(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	cube->texture->rendu = mlx_new_image(cube->mlx, NB_RAY, HEIGHT);
	mlx_image_to_window(cube->mlx, cube->texture->rendu, 0, 0);
	create_minimap(cube);
	image_to_map(cube,i,j);
	create_circle(cube);
	create_person(cube);
	// invert_image(cube->texture->south);
	// invert_image(cube->texture->west);
}
