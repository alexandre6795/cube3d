/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_minimapuser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:32:14 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/19 09:33:39 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	create_p(t_cube *cube, int i, int j)
{
	while (cube->map->map[i])
	{
		j = 0;
		while (cube->map->map[i][j])
		{
			if (cube->map->map[i][j] == 'N' || cube->map->map[i][j] == 'S'
				|| cube->map->map[i][j] == 'E' || cube->map->map[i][j] == 'W')
				mlx_image_to_window(cube->mlx, cube->texture->red, j * 64 + 16,
					i * 64 + 16);
			if (cube->map->map[i][j] == 'N')
				cube->player->angle = 90;
			else if (cube->map->map[i][j] == 'E')
				cube->player->angle = 0;
			else if (cube->map->map[i][j] == 'S')
				cube->player->angle = 270;
			else if (cube->map->map[i][j] == 'W')
				cube->player->angle = 180;
			j++;
		}
		i++;
	}
}

int	create_person(t_cube *cube)
{
	create_p(cube, 0, 0);
	return (0);
}