/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:20:15 by akastler          #+#    #+#             */
/*   Updated: 2024/01/09 08:37:45 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	open_textures(t_cube *cube)
{
	int	i;

	i = -1;
	while (cube->texture->path[++i])
	{
		if (ft_strncmp(cube->texture->path[i], "NO", 2) == 0)
			cube->texture->nord = mlx_load_png(cube->texture->path[i]
					+ skip_wp(cube->texture->path[i] + 2) + 2);
		else if (ft_strncmp(cube->texture->path[i], "SO", 2) == 0)
			cube->texture->south = mlx_load_png(cube->texture->path[i]
					+ skip_wp(cube->texture->path[i] + 2) + 2);
		else if (ft_strncmp(cube->texture->path[i], "EA", 2) == 0)
			cube->texture->est = mlx_load_png(cube->texture->path[i]
					+ skip_wp(cube->texture->path[i] + 2) + 2);
		else if (ft_strncmp(cube->texture->path[i], "WE", 2) == 0)
			cube->texture->west = mlx_load_png(cube->texture->path[i]
					+ skip_wp(cube->texture->path[i] + 2) + 2);
	}
	cube->texture->door[0] = mlx_load_png("img/door_open.png");
	cube->texture->door[1] = mlx_load_png("img/door_close.png");
	if (!cube->texture->nord || !cube->texture->south || !cube->texture->est
		|| !cube->texture->west || !cube->texture->door[0]
		|| !cube->texture->door[1])
		return (ft_error("Texture not found"));
	return (0);
}

int	verify_texture(t_cube *cube)
{
	if (cube->texture->nord->height != cube->texture->nord->width
		|| cube->texture->south->height != cube->texture->south->width
		|| cube->texture->west->height != cube->texture->west->width
		|| cube->texture->est->height != cube->texture->est->width
		|| cube->texture->door[0]->height != cube->texture->door[0]->width
		|| cube->texture->door[1]->height != cube->texture->door[1]->width)
		return (ft_error("one of the texture is not a square"));
	return (0);
}

int	graphique_load(t_cube *cube)
{
	if (open_textures(cube) != 0 || open_rgb(cube) != 0
		|| verify_texture(cube) != 0)
		return (1);
	return (0);
}
