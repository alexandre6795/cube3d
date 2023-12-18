/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:52:07 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/18 13:24:39 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	drawline(int xStart, int yStart, int xStop, int yStop, t_cube *cube)
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

void	default_ray(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < NB_RAY)
	{
		cube->player->ray[i].x = cube->player->x;
		cube->player->ray[i].y = cube->player->y;
		cube->player->ray[i].dist = 0;
		cube->player->ray[i].angle = cube->player->angle;
		i++;
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
