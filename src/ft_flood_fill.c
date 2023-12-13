/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:21:29 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/13 14:44:08 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"


int ma_direction(char **map,int i ,int j)
{
	if ((map[i - 1][j] != '1' && map[i - 1][j] != '0' && map[i - 1][j] != 'N'
			&& map[i - 1][j] != 'S' && map[i - 1][j] != 'E'
			&& map[i - 1][j] != 'W' && map[i - 1][j] != 'D')
		|| (map[i + 1][j] != '1' && map[i + 1][j] != '0' && map[i + 1][j] != 'N'
			&& map[i + 1][j] != 'S' && map[i + 1][j] != 'E'
			&& map[i + 1][j] != 'W' && map[i + 1][j] != 'D')
		|| (map[i][j - 1] != '1' && map[i][j - 1] != '0' && map[i][j - 1] != 'N'
			&& map[i][j - 1] != 'S' && map[i][j - 1] != 'E'
			&& map[i][j - 1] != 'W' && map[i][j - 1] != 'D')
		|| (map[i][j + 1] != '1' && map[i][j + 1] != '0' && map[i][j + 1] != 'N'
			&& map[i][j + 1] != 'S' && map[i][j + 1] != 'E'
			&& map[i][j + 1] != 'W' && map[i][j + 1] != 'D'))
		return (1);
	return (0);
}


int	verif(char **map)
{
	int	j;
	int	i;

	i = -1;
	while (map[++i])
	{
			j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				if (i == 0 || i == ft_tablen(map) - 1 || j == 0
					|| j == (int)ft_strlen(map[i]) - 1 || j > (int)ft_strlen(map[i - 1]) - 1 ||!map[i - 1][j] || j > (int)ft_strlen(map[i + 1]) - 1 || !map[i + 1][j]  || ma_direction(map,i,j)==1)
				{
					return (1);
				}
		}
	}
	return(0);
}

int	ft_flood_fill(t_cube *cube)
{
	char		**copy;

	copy = copy_tab(cube->map->map);
	if (verif(copy) == 1)
		return(ft_free_tab(copy, 1));
	return(ft_free_tab(copy, 0));
}
