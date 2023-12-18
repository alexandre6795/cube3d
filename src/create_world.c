/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:19:19 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/18 13:07:37 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	create_image(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	cube->texture->black = mlx_new_image(cube->mlx, 64, 64);
	cube->texture->white = mlx_new_image(cube->mlx, 64, 64);
	cube->texture->red = mlx_new_image(cube->mlx, 32, 32);
	cube->texture->green = mlx_new_image(cube->mlx, cube->map->size_y * 64,
			cube->map->size_x * 64);
	while (i < cube->map->size_x * 64)
	{
		j = 0;
		while (j < cube->map->size_y * 64)
		{
			if (i < 64 && j < 64)
			{
				mlx_put_pixel(cube->texture->black, i, j, rgba(0, 0, 0, 255));
				mlx_put_pixel(cube->texture->white, i, j, rgba(222, 222, 222,
						100));
			}
			if (i < 32 && j < 32)
				mlx_put_pixel(cube->texture->red, i, j, rgba(222, 0, 0, 100));
			j++;
		}
		i++;
	}
}

int	create_person(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cube->map->map[i])
	{
		j = 0;
		while (cube->map->map[i][j])
		{
			if (cube->map->map[i][j] == 'N' || cube->map->map[i][j] == 'S'
				|| cube->map->map[i][j] == 'E' || cube->map->map[i][j] == 'W')
				mlx_image_to_window(cube->mlx, cube->texture->red, j * 64 + 16,
					i * 64 + 16);
			if (cube->map->map[i][j] == 'N')
				cube->player->angle = 90;
			else if (cube->map->map[i][j] == 'E')
				cube->player->angle = 0;
			else if (cube->map->map[i][j] == 'S')
				cube->player->angle = 270;
			else if (cube->map->map[i][j] == 'W')
				cube->player->angle = 180;
			j++;
		}
		i++;
	}
	return (0);
}

void	image_to_map(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cube->map->map[i])
	{
		j = 0;
		while (cube->map->map[i][j])
		{
			if (cube->map->map[i][j] == '1')
				mlx_image_to_window(cube->mlx, cube->texture->black, j * 64, i
					* 64);
			else if (cube->map->map[i][j] == '0')
				mlx_image_to_window(cube->mlx, cube->texture->white, j * 64, i
					* 64);
			j++;
		}
		i++;
	}
	mlx_image_to_window(cube->mlx, cube->texture->green, 0, 0);
}

void	drawLine(int xStart, int yStart, int xStop, int yStop, t_cube *cube)
{
	int	xInc;
	int	yInc;

	int dx, dy, p, x, y;
	// Calculer les variations en x et y
	dx = xStop - xStart;
	dy = yStop - yStart;
	// Calculer les incréments pour x et y
	xInc = (dx > 0) ? 1 : -1;
	yInc = (dy > 0) ? 1 : -1;
	// Prendre la valeur absolue des variations
	dx = (dx < 0) ? -dx : dx;
	dy = (dy < 0) ? -dy : dy;
	// Initialiser les coordonnées de départ
	x = xStart;
	y = yStart;
	// Dessiner le pixel initial
	mlx_put_pixel(cube->texture->green, x, y, rgba(0, 240, 0, 150));
	// Dessiner la ligne en utilisant l'algorithme de Bresenham
	if (dx > dy)
	{
		p = 2 * dy - dx;
		for (int i = 0; i < dx; i++)
		{
			x += xInc;
			if (p >= 0)
			{
				y += yInc;
				p -= 2 * dx;
			}
			p += 2 * dy;
			mlx_put_pixel(cube->texture->green, x, y, rgba(0, 240, 0, 150));
		}
	}
	else
	{
		p = 2 * dx - dy;
		for (int i = 0; i < dy; i++)
		{
			y += yInc;
			if (p >= 0)
			{
				x += xInc;
				p -= 2 * dy;
			}
			p += 2 * dx;
			mlx_put_pixel(cube->texture->green, x, y, rgba(0, 240, 0, 150));
		}
	}
}

void	resetImageRay(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cube->map->size_x * 64)
	{
		j = 0;
		while (j < cube->map->size_y * 64)
		{
			mlx_put_pixel(cube->texture->green, j, i, rgba(0, 0, 0, 0));
			j++;
		}
		i++;
	}
}

void	create_ray(void *arg)
{
	t_cube	*cube;

	cube = arg;
	// int	i;
	// int	j;
	// i = 0;
	// j = 0;
	resetImageRay(cube);
	default_ray(cube);
	drawLine(cube->texture->red->instances[0].x,
		cube->texture->red->instances[0].y, 100, 100, cube);
}

void	create_world(t_cube *cube)
{
	create_image(cube);
	create_person(cube);
	// create_ray(cube);
	image_to_map(cube);
}