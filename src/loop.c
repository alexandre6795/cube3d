/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:12:52 by aherrman          #+#    #+#             */
/*   Updated: 2024/01/23 11:14:25 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	loop_hook(void *param)
{
	t_cube	*cube;

	cube = param;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cube->mlx);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_S))
		ft_movedown(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_W))
		ft_moveup(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_A))
		ft_moveleft(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_D))
		ft_moveright(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_LEFT))
		rot_left(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_RIGHT))
		rot_right(cube);
}

void	determinate_hitted(t_cube *cube, int ray_nbr)
{
	if (cube->player->ray[ray_nbr].hitted == 1)
	{
		if (cube->player->ray[ray_nbr].angle > 0
			&& cube->player->ray[ray_nbr].angle < PI)
			cube->player->ray[ray_nbr].hitted = 3;
		else
			cube->player->ray[ray_nbr].hitted = 1;
	}
	else
	{
		if (cube->player->ray[ray_nbr].angle > PI / 2
			&& cube->player->ray[ray_nbr].angle < 3 * PI / 2)
			cube->player->ray[ray_nbr].hitted = 4;
		else
			cube->player->ray[ray_nbr].hitted = 2;
	}
}

float	*get_smallest_ray(t_cube *cube, int ray_nbr)
{
	float	*stop;
	float	*stop2;
	float	wall_hit_dist_hv[2];

	stop = wall_collision_vert(cube, &cube->player->ray[ray_nbr]);
	stop2 = wall_collision_hori(cube, &cube->player->ray[ray_nbr]);
	wall_hit_dist_hv[1] = sqrtf(powf(cube->player->x - stop[0], 2)
			+ powf(cube->player->y - stop[1], 2));
	wall_hit_dist_hv[0] = sqrtf(powf((cube->player->x) - stop2[0], 2)
			+ powf((cube->player->y) - stop2[1], 2));
	cube->player->ray[ray_nbr].hitted = 0;
	cube->player->ray[ray_nbr].dist = wall_hit_dist_hv[1];
	if (wall_hit_dist_hv[1] > wall_hit_dist_hv[0])
	{
		cube->player->ray[ray_nbr].hitted = 1;
		cube->player->ray[ray_nbr].dist = wall_hit_dist_hv[0];
		cube->player->ray[ray_nbr].block_type[0]
			= cube->player->ray[ray_nbr].block_type[1];
		stop[0] = stop2[0];
		stop[1] = stop2[1];
	}
	determinate_hitted(cube, ray_nbr);
	free(stop2);
	return (stop);
}

void	loop_ray(void *arg)
{
	t_cube	*cube;
	float	*stop;
	int		i;

	i = 0;
	cube = arg;
	reset_image_ray(cube);
	default_ray(cube);
	while (i < NB_RAY)
	{
		stop = get_smallest_ray(cube, i);
		drawline((int [2]){cube->player->x / 4, cube->player->y / 4},
			(int [2]){(int)stop[0] / 4, (int)stop[1] / 4}, cube);
		cube->player->ray[i].x = stop[0];
		cube->player->ray[i].y = stop[1];
		cube->player->ray[i].invx = stop[0];
		cube->player->ray[i].invy = stop[1];
		draw_3d(cube, i);
		free(stop);
		i++;
	}
}

void	key_hook(mlx_key_data_t keydata, void *arg)
{
	t_cube	*cube;

	cube = arg;
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
		hodor(cube);
	else if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		change_mouse(cube);
}
