/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:08:31 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/19 10:24:07 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

// x = 0 y = 1

void	default_value(int *d, int *inc)
{
	if (d[0] >= 0)
		inc[0] = 1;
	else
		inc[0] = -1;
	if (d[1] >= 0)
		inc[1] = 1;
	else
		inc[1] = -1;
	if (d[0] < 0)
		d[0] = -d[0];
	if (d[1] < 0)
		d[1] = -d[1];
}

void	dl1(t_cube *cube, int *pos, int *d, int *inc)
{
	int	i;

	i = 0;
	pos[2] = 2 * d[1] - d[0];
	while (i < d[0])
	{
		pos[0] += inc[0];
		if (pos[2] >= 0)
		{
			pos[1] += inc[1];
			pos[2] -= 2 * d[0];
		}
		pos[2] += 2 * d[1];
		mlx_put_pixel(cube->texture->green, pos[0], pos[1], rgba(0, 240, 0,
				150));
		i++;
	}
}
void	dl2(t_cube *cube, int *pos, int *d, int *inc)
{
	int i;
	i = 0;
	pos[2] = 2 * d[0] - d[1];
	while (i < d[1])
	{
		pos[1] += inc[1];
		if (pos[2] >= 0)
		{
			pos[0] += inc[0];
			pos[2] -= 2 * d[1];
		}
		pos[2] += 2 * d[0];
		mlx_put_pixel(cube->texture->green, pos[0], pos[1], rgba(0, 240, 0,
				150));
		i++;
	}
}