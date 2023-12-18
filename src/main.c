/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:48:41 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/18 13:01:51 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

// int	main(int ac, char **av)
// {
// 	t_cube	*cube;

// 	ft_valid_av(ac, av);
// 	cube = malloc(sizeof(t_cube));
// 	ft_ini_cube(cube);
// 	ft_valid_cube(av[1], cube);
// 	cube->pic = (t_mlx *)malloc(sizeof(t_mlx));
// 	cube->mlx = mlx_init(32 * cube->msize->y, 32 * cube->msize->x, "MLX42",
// 			true);
// 	if (!(cube->mlx))
// 		ft_error("can t open cube sorry :/", cube);
// 	mlx_set_setting(MLX_STRETCH_IMAGE, true);
// 	ft_create_word(cube->pic, cube, cube->mlx);
// 	mlx_key_hook(cube->mlx, &ft_keyhook, cube);
// 	mlx_loop(cube->mlx);
// 	ft_clean(cube->pic, cube->mlx);
// 	if (cube->pic != NULL)
// 		free(cube->pic);
// 	ft_free(cube);
// 	mlx_terminate(cube->mlx);
// 	return (0);
// }
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
	init_for_mlx(cube);
	cube->map = malloc(sizeof(t_map));
	cube->map->map = NULL;
	init_ray(cube);
}
void	mlx_hook(void *param)
{
	t_cube	*cube;

	cube = param;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cube->mlx);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_W))
	{
		cube->texture->red->instances[0].y += 10;
	}
	// 	ft_moveup(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_S))
		cube->texture->red->instances[0].y -= 10;
	// 	ft_movedown(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_A))
		cube->texture->red->instances[0].x += 10;
	// 	ft_moveleft(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_D))
		cube->texture->red->instances[0].x -= 10;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_LEFT))
		cube->texture->red->instances[0].z += 10;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_RIGHT))
		cube->texture->red->instances[0].z -= 10;
	// 	ft_moveright(cube);
	// ft_anim_on_key(cube);
}
int	main(int ac, char **av)
{
	t_cube *cube;

	cube = malloc(sizeof(t_cube));
	init_cube(cube);
	if (ft_valid_arg(ac, av, cube) == 0)
	{
		sizemap(cube);
		if (graphique_load(cube) == 0)
		{
			cube->mlx = mlx_init(64 * cube->map->size_y, 64 * cube->map->size_x,
					"MLX42", true);
			if (!(cube->mlx))
				ft_error("can t open cube sorry");
			mlx_set_setting(MLX_STRETCH_IMAGE, true);
			create_world(cube);
			mlx_loop_hook(cube->mlx, &mlx_hook, cube);
			mlx_loop_hook(cube->mlx, &create_ray, cube);
			
			mlx_loop(cube->mlx);
		}
	}
	ft_free_all(cube);
}