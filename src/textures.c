/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:20:15 by akastler          #+#    #+#             */
/*   Updated: 2023/12/21 11:11:02 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	open_textures(t_cube *cube)
{
	int	i;

	i = 0;
	while (cube->texture->path[i])
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
		i++;
	}
	if (!cube->texture->nord || !cube->texture->south || !cube->texture->est
		|| !cube->texture->west)
		return (ft_error("Texture not found"));
	return (0);
}

int	graphique_load(t_cube *cube)
{
	if (open_textures(cube) != 0 || open_rgb(cube) != 0)
		return (1);
	return (0);
}
