/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:17:21 by aherrman          #+#    #+#             */
/*   Updated: 2024/01/03 10:41:55 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	free_all_mlx(t_cube *cube)
{
	if (cube->texture->floor != NULL)
		free(cube->texture->floor);
	if (cube->texture->sky != NULL)
		free(cube->texture->sky);
	if (cube->texture->nord != NULL)
		mlx_delete_texture(cube->texture->nord);
	if (cube->texture->south != NULL)
		mlx_delete_texture(cube->texture->south);
	if (cube->texture->est != NULL)
		mlx_delete_texture(cube->texture->est);
	if (cube->texture->west != NULL)
		mlx_delete_texture(cube->texture->west);
}

void	free_all_char(t_cube *cube)
{
	if (cube->map->map != NULL)
		ft_free_tab(cube->map->map, 0);
	if (cube->texture->path != NULL)
		ft_free_tab(cube->texture->path, 0);
}

void	free_all_player(t_cube *cube)
{
	if (cube->player->ray)
		free(cube->player->ray);
}

void	ft_free_all(t_cube *cube)
{
	free_all_mlx(cube);
	free_all_char(cube);
	free(cube->start);
	free_all_player(cube);
	free(cube->player);
	if (cube->texture->black)
		mlx_delete_image(cube->mlx, cube->texture->black);
	if (cube->texture->white)
		mlx_delete_image(cube->mlx, cube->texture->white);
	if (cube->texture->red)
		mlx_delete_image(cube->mlx, cube->texture->red);
	if (cube->texture->circle)
		mlx_delete_image(cube->mlx, cube->texture->circle);
	free(cube->texture);
	free(cube->map);
	if (cube->mlx)
		mlx_close_window(cube->mlx);
	if (cube->mlx != NULL)
		mlx_terminate(cube->mlx);
	free(cube);
}
