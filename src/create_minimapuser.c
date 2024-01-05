/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_minimapuser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:32:14 by aherrman          #+#    #+#             */
/*   Updated: 2024/01/04 15:33:59 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	set_p_angle(t_cube *cube, char dir)
{
	if (dir == 'N')
		cube->player->angle = convert_deg_pirad(270);
	else if (dir == 'E')
		cube->player->angle = 0;
	else if (dir == 'S')
		cube->player->angle = convert_deg_pirad(90);
	else if (dir == 'W')
		cube->player->angle = convert_deg_pirad(180);
}

void	create_p(t_cube *cube, int i, int j)
{
	char	dir;

	dir = 0;
	while (cube->map->map[i] && dir == 0)
	{
		j = 0;
		while (cube->map->map[i][j] && dir == 0)
		{
			if ((cube->map->map[i][j] == 'N' || cube->map->map[i][j] == 'S'
				|| cube->map->map[i][j] == 'E' || cube->map->map[i][j] == 'W'))
			{
				mlx_image_to_window(cube->mlx, cube->texture->circle,
					j * 16 + 8 - 4, i * 16 + 8 - 4);
				dir = cube->map->map[i][j];
			}
			j++;
		}
		i++;
	}
	set_p_angle(cube, dir);
	cube->player->x = cube->texture->circle->instances[0].x * 4 + 4;
	cube->player->y = cube->texture->circle->instances[0].y * 4 + 4;
}

int	create_person(t_cube *cube)
{
	create_p(cube, 0, 0);
	return (0);
}
