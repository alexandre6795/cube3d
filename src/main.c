/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:48:41 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/05 14:23:00 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"



int	main(int ac, char **av)
{
	t_game	*game;

	ft_valid_av(ac, av);
	game = malloc(sizeof(t_game));
	ft_ini_game(game);
	ft_valid_game(av[1], game);
	game->pic = (t_mlx *)malloc(sizeof(t_mlx));
	game->mlx = mlx_init(32 * game->msize->y, 32 * game->msize->x, "MLX42",
			true);
	if (!(game->mlx))
		ft_error("can t open game sorry :/", game);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	ft_create_word(game->pic, game, game->mlx);
	mlx_key_hook(game->mlx, &ft_keyhook, game);
	mlx_loop(game->mlx);
	ft_clean(game->pic, game->mlx);
	if (game->pic != NULL)
		free(game->pic);
	ft_free(game);
	mlx_terminate(game->mlx);
	return (0);
}

int main (int ac , char **av)
{
	t_cube *cube;
	ft_valid_arg(ac,av);
}
