/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:59:08 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/21 11:51:11 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	copy_map(char **file, int start, t_cube *cube)
{
	int	i;
	int	j;

	i = start;
	j = 0;
	cube->map->map = ft_calloc(ft_tablen(file) + 1, sizeof(char *));
	while (file[i])
	{
		cube->map->map[j] = ft_strdup(file[i]);
		i++;
		j++;
	}
}

void	need_line(char c, int i, int j, t_cube *cube)
{
	cube->start->sens = c;
	cube->start->x = i - cube->map->startline;
	cube->start->y = j;
}

int	invalid_char(char **file, int start)
{
	int	i;
	int	j;

	i = start;
	j = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
		{
			if (file[i][j] != '1' && file[i][j] != 'D' && file[i][j] != '0'
				&& file[i][j] != 'N' && file[i][j] != 'S' && file[i][j] != 'E'
				&& file[i][j] != 'W' && file[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_perso(char **file, int start, t_cube *cube)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = start - 1;
	j = -1;
	while (file[++i])
	{
		j = -1;
		while (file[i][++j])
		{
			if (file[i][j] == 'N' || file[i][j] == 'S' || file[i][j] == 'E'
				|| file[i][j] == 'W')
			{
				count++;
				need_line(file[i][j], i, j, cube);
			}
		}
	}
	if (count != 1)
		return (1);
	copy_map(file, start, cube);
	return (0);
}

int	valid_tex(char *file)
{
	if (ft_strncmp(file, "NO", 2) == 0 || ft_strncmp(file, "SO", 2) == 0
		|| ft_strncmp(file, "WE", 2) == 0 || ft_strncmp(file, "EA", 2) == 0
		|| ft_strncmp(file, "C", 1) == 0 || ft_strncmp(file, "F", 1) == 0)
		return (1);
	return (0);
}
