/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:10:11 by akastler          #+#    #+#             */
/*   Updated: 2023/12/21 11:36:18 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	initbressenham(t_bressenham *br)
{
	br->dx = 0;
	br->dy = 0;
	br->xinc = 0;
	br->yinc = 0;
	br->x = 0;
	br->y = 0;
	br->p = 0;
	br->i = 0;
}

void	bressenhamdxsup(t_bressenham *br, t_cube *cube)
{
	br->p = 2 * br->dy - br->dx;
	while (br->i < br->dx)
	{
		br->x += br->xinc;
		if (br->p >= 0)
		{
			br->y += br->yinc;
			br->p -= 2 * br->dx;
		}
		br->p += 2 * br->dy;
		mlx_put_pixel(cube->texture->green, br->x, br->y, rgba(0, 240, 0, 150));
		br->i++;
	}
}

void	breseenhamdysup(t_bressenham *br, t_cube *cube)
{
	br->p = 2 * br->dx - br->dy;
	while (br->i < br->dy)
	{
		br->y += br->yinc;
		if (br->p >= 0)
		{
			br->x += br->xinc;
			br->p -= 2 * br->dy;
		}
		br->p += 2 * br->dx;
		mlx_put_pixel(cube->texture->green, br->x, br->y, rgba(0, 240, 0, 150));
		br->i++;
	}
}

void	bressenhamtern(t_bressenham *br)
{
	if (br->dx < 0)
	{
		br->dx = -br->dx;
		br->xinc = -1;
	}
	else
		br->xinc = 1;
	if (br->dy < 0)
	{
		br->dy = -br->dy;
		br->yinc = -1;
	}
	else
		br->yinc = 1;
}

// void	drawline(int xStart, int yStart, int xStop, int yStop, t_cube *cube)
void	drawline(int startxy[2], int stopxy[2], t_cube *cube)
{
	t_bressenham	br;

	initbressenham(&br);
	br.dx = stopxy[0] - startxy[0];
	br.dy = stopxy[1] - startxy[1];
	bressenhamtern(&br);
	br.x = startxy[0];
	br.y = startxy[1];
	mlx_put_pixel(cube->texture->green, br.x, br.y, rgba(0, 240, 0, 150));
	if (br.dx > br.dy)
		bressenhamdxsup(&br, cube);
	else
		breseenhamdysup(&br, cube);
}
