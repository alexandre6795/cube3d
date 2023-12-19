/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:52:07 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/19 12:06:40 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

// x = 0 y = 1

int	*wall_collision(t_cube *cube, t_ray ray)
{
	int	*stop;
	int	map_x;
	int	map_y;

	stop = malloc(sizeof(int) * 2);
	stop[0] = ray.x;
	stop[1] = ray.y;
	float step_x = cos(ray.angle);
		// Calcul du pas en x basé sur l'angle du rayon
	float step_y = sin(ray.angle);
		// Calcul du pas en y basé sur l'angle du rayon
	while (stop[0] >= 0 && stop[1] >= 0 && stop[0] < cube->map->size_x * 64
		&& stop[1] < cube->map->size_x * 64)
	{
		map_x = stop[0] / 64;
		map_y = stop[1] / 64;
		if (cube->map->map[map_y][map_x] == '1')
		{
			// Arrêt lorsque le mur est atteint
			break ;
		}
		stop[0] += step_x;
		stop[1] += step_y;
	}
	printf("stop[0] = %d\n", stop[0]);
	printf("stop[1] = %d\n", stop[1]);
	return (stop);
}

void	drawline(int xstart, int ystart, int xstop, int ystop, t_cube *cube)
{
	int	inc[2];
	int	d[2];
	int	pos[3];
	int	*stop;

	(void)xstop;
	(void)ystop;
	stop = wall_collision(cube, cube->player->ray[0]);
	d[0] = stop[0] - xstart;
	d[1] = stop[1] - ystart;
	pos[0] = xstart + 16;
	pos[1] = ystart;
	default_value(d, inc);
	// Dessiner le pixel initial
	mlx_put_pixel(cube->texture->green, pos[0], pos[1], rgba(0, 240, 0, 150));
	// Dessiner la ligne en utilisant l'algorithme de Bresenham
	if (d[0] > d[1])
		dl1(cube, pos, d, inc);
	else
		dl2(cube, pos, d, inc);
}

void	default_ray(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < NB_RAY)
	{
		cube->player->ray[i].x = cube->texture->red->instances[0].x;
		cube->player->ray[i].y = cube->texture->red->instances[0].y;
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
