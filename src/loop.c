/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:12:52 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/19 11:52:45 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	loop_hook(void *param)
{
	t_cube *cube;

	cube = param;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cube->mlx);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_S))
	{
		cube->texture->red->instances[0].y += 10;
	}
	if (mlx_is_key_down(cube->mlx, MLX_KEY_W))
		cube->texture->red->instances[0].y -= 10;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_D))
		cube->texture->red->instances[0].x += 10;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_A))
		cube->texture->red->instances[0].x -= 10;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_LEFT))
	rot_left(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_RIGHT))
	rot_right(cube);
}
void	loop_ray(void *arg)
{
	t_cube	*cube;

	cube = arg;
	resetImageRay(cube);
	default_ray(cube);
	drawline(cube->texture->red->instances[0].x,
		cube->texture->red->instances[0].y, 100, 100, cube);
}
