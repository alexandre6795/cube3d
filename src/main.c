/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:48:41 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/12 09:17:13 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

// int	main(int ac, char **av)
// {
// 	t_game	*game;

// 	ft_valid_av(ac, av);
// 	game = malloc(sizeof(t_game));
// 	ft_ini_game(game);
// 	ft_valid_game(av[1], game);
// 	game->pic = (t_mlx *)malloc(sizeof(t_mlx));
// 	game->mlx = mlx_init(32 * game->msize->y, 32 * game->msize->x, "MLX42",
// 			true);
// 	if (!(game->mlx))
// 		ft_error("can t open game sorry :/", game);
// 	mlx_set_setting(MLX_STRETCH_IMAGE, true);
// 	ft_create_word(game->pic, game, game->mlx);
// 	mlx_key_hook(game->mlx, &ft_keyhook, game);
// 	mlx_loop(game->mlx);
// 	ft_clean(game->pic, game->mlx);
// 	if (game->pic != NULL)
// 		free(game->pic);
// 	ft_free(game);
// 	mlx_terminate(game->mlx);
// 	return (0);
// }
void	init_for_mlx(t_cube *cube)
{
	cube->texture->path = malloc(sizeof(char *) * 7);
	cube->texture->path[6] = NULL;
	cube->texture->nord = NULL;
	cube->texture->south = NULL;
	cube->texture->est = NULL;
	cube->texture->west = NULL;
	cube->texture->floor = NULL;
	cube->texture->sky = NULL;
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
	cube->texture = malloc(sizeof(t_image));
	init_for_mlx(cube);
	cube->map = malloc(sizeof(t_map));
}

int	main(int ac, char **av)
{
	t_cube *cube;

	cube = malloc(sizeof(t_cube));
	init_cube(cube);
	ft_valid_arg(ac, av, cube);
	print_map(cube);
	// cube->mlx = mlx_init(32 * cube->map->size_y, 32 * cube->map->size_y,
	// 		"MLX42", true);
	// if (!(cube->mlx))
	// 	ft_error("can t open game sorry :/);
	ft_free_all(cube);
}