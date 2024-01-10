/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:48:41 by aherrman          #+#    #+#             */
/*   Updated: 2024/01/10 11:02:49 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	init_for_mlx(t_cube *cube)
{
	cube->texture->path = ft_calloc(7, sizeof(char *));
	cube->texture->nord = NULL;
	cube->texture->south = NULL;
	cube->texture->est = NULL;
	cube->texture->west = NULL;
	cube->texture->floor = NULL;
	cube->texture->sky = NULL;
	cube->texture->black = NULL;
	cube->texture->white = NULL;
	cube->texture->red = NULL;
	cube->texture->circle = NULL;
	cube->texture->rendu = NULL;
	cube->texture->door[0] = NULL;
	cube->texture->door[1] = NULL;
	cube->mlx = NULL;
}

void	init_ray(t_cube *cube)
{
	int	i;

	i = 0;
	cube->player->ray = ft_calloc(NB_RAY + 1, sizeof(t_ray));
	while (i < NB_RAY)
	{
		cube->player->ray[i].x = 0;
		cube->player->ray[i].y = 0;
		cube->player->ray[i].angle = 0;
		cube->player->ray[i].dist = 0;
		i++;
	}
}

void	init_cube(t_cube *cube)
{
	cube->start = malloc(sizeof(t_startpos));
	cube->start->x = 0;
	cube->start->y = 0;
	cube->start->sens = 0;
	cube->player = malloc(sizeof(t_player));
	cube->player->x = 0;
	cube->player->y = 0;
	cube->player->angle = 0;
	cube->player->fov = 60;
	cube->texture = malloc(sizeof(t_image));
	cube->player->projection_plane = ((NB_RAY / 2) / tan(30 * PI / 180));
	init_for_mlx(cube);
	cube->map = malloc(sizeof(t_map));
	cube->map->map = NULL;
	cube->cursor = malloc(sizeof(t_cursor));
	cube->cursor->originx = NB_RAY / 2;
	cube->cursor->originy = HEIGHT / 2;
	cube->cursor->stuck = false;
	init_ray(cube);
}

void	loop(t_cube *cube)
{
	mlx_loop_hook(cube->mlx, &loop_ray, cube);
	mlx_loop_hook(cube->mlx, &loop_hook, cube);
	mlx_key_hook(cube->mlx, &key_hook, cube);
	mlx_cursor_hook(cube->mlx, &cursor_hook, cube);
}

int	main(int ac, char **av)
{
	t_cube	*cube;

	cube = malloc(sizeof(t_cube));
	init_cube(cube);
	if (ft_valid_arg(ac, av, cube) == 0)
	{
		sizemap(cube);
		if (graphique_load(cube) == 0)
		{
			cube->mlx = mlx_init(NB_RAY, HEIGHT, "MLX42", true);
			if (!(cube->mlx))
				ft_error("can t open cube sorry");
			mlx_set_setting(MLX_STRETCH_IMAGE, true);
			create_world(cube);
			loop(cube);
			mlx_loop(cube->mlx);
		}
	}
	ft_free_all(cube);
}
