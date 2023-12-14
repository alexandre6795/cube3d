/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:20:15 by akastler          #+#    #+#             */
/*   Updated: 2023/12/14 12:21:09 by aherrman         ###   ########.fr       */
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
		return (ft_error("Error: Texture not found"));
	return (0);
}

int	*create_rgb(int r, int g, int b)
{
	int	*rgb;

	rgb = malloc(sizeof(int) * 3);
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
	return (rgb);
}

int	rgb_create(char *str, t_cube *cube, char c)
{
	char	**splited;
	int		tmp[3];

	splited = ft_split(str, ',');
	if (ft_tablen(splited) != 3)
		return (ft_free_tab(splited, ft_error("Error: RGB not valid")));
	tmp[0] = ft_atoi(splited[0]);
	tmp[1] = ft_atoi(splited[1]);
	tmp[2] = ft_atoi(splited[2]);
	if (tmp[0] < 0 || tmp[0] > 255 || tmp[1] < 0 || tmp[1] > 255 || tmp[2] < 0
		|| tmp[2] > 255)
		return (ft_free_tab(splited, ft_error("Error: RGB not valid")));
	if (c == 'F')
		cube->texture->floor = create_rgb(tmp[0], tmp[1], tmp[2]);
	else if (c == 'C')
		cube->texture->sky = create_rgb(tmp[0], tmp[1], tmp[2]);
	return (ft_free_tab(splited, 0));
}

int	open_rgb(t_cube *cube)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (cube->texture->path[i])
	{
		if (ft_strncmp(cube->texture->path[i], "F", 1) == 0)
		{
			ret += rgb_create(cube->texture->path[i]
					+ skip_wp(cube->texture->path[i] + 1) + 1, cube, 'F');
		}
		else if (ft_strncmp(cube->texture->path[i], "C", 1) == 0)
		{
			ret += rgb_create(cube->texture->path[i]
					+ skip_wp(cube->texture->path[i] + 1) + 1, cube, 'C');
		}
		i++;
	}
	if (ret != 0)
		return (1);
	return (0);
}
int	graphique_load(t_cube *cube)
{
	if (open_textures(cube) != 0 || open_rgb(cube) != 0)
		return (1);
	return (0);
}