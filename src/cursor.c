/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:26:05 by akastler          #+#    #+#             */
/*   Updated: 2024/01/10 10:52:05 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	cursor_hook(double x, double y, void *param)
{
	t_cube *cube;

	cube = (t_cube *)param;
	(void)y;
	// if (cube->cursor->stuck == false)
	//     return ;

	cube->player->angle += (x - cube->cursor->originx) / 10000;
	if (cube->player->angle > 2 * PI)
		cube->player->angle -= 2 * PI;
	if (cube->player->angle < 0)
		cube->player->angle += 2 * PI;
	mlx_set_mouse_pos(cube->mlx, cube->cursor->originx, cube->cursor->originy);
}