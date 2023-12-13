/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:17:21 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/13 14:33:52 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	free_all_mlx(t_cube *cube)
{
	if (cube->texture->nord != NULL)
		mlx_delete_texture(cube->texture->nord);
	if (cube->texture->south != NULL)
		mlx_delete_texture(cube->texture->south);
	if (cube->texture->est != NULL)
		mlx_delete_texture(cube->texture->est);
	if (cube->texture->west != NULL)
		mlx_delete_texture(cube->texture->west);
	// if (cube->texture->floor != NULL)
	// 	mlx_delete_texture(cube->texture->floor);
	// if (cube->texture->sky != NULL)
	// 	mlx_delete_texture(cube->texture->sky);
	if (cube->mlx != NULL)
		mlx_terminate(cube->mlx);
}

void	free_all_char(t_cube *cube)
{
	if (cube->map->map != NULL)
		ft_free_tab(cube->map->map, 0);
	if (cube->texture->path != NULL)
		ft_free_tab(cube->texture->path, 0);
}

void	ft_free_all(t_cube *cube)
{
	free_all_mlx(cube);
	free_all_char(cube);
	free(cube->start);
	free(cube->player);
	free(cube->texture);
	free(cube->map);
	free(cube);
}