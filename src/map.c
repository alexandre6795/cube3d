/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:59:08 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/12 11:20:29 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	start_map(char **file, int len, bool j)
{
	int	i;

	if (j == true)
	{
		i = 0;
		while (i < len)
		{
			file[i] = ft_strtrim(file[i], " ");
			if (ft_strncmp(file[i], "1", 1) == 0)
				return (i);
			i++;
		}
	}
	else
	{
		i = len - 1;
		while (i > 0)
		{
			file[i] = ft_strtrim(file[i], " ");
			if (ft_strncmp(file[i], "1", 1) == 0)
				return (i);
			i--;
		}
	}
	return (0);
}
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
	cube->start->x = i;
	cube->start->y = j;
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
	if (count == true)
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
