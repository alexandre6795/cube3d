/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:59:08 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/12 10:01:02 by aherrman         ###   ########.fr       */
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
	while (file[i])
	{
		cube->map->map[j] = ft_strdup(file[i]);
		i++;
		j++;
	}
}
int	valid_perso(char **file, int start, t_cube *cube)
{
	int	i;
	int	j;
	int	count;

	i = start - 1;
	j = -1;
	count = 0;
	while (file[++i])
	{
		j = -1;
		while (file[i][++j])
		{
			if (file[i][j] == 'N' || file[i][j] == 'S' || file[i][j] == 'E'
				|| file[i][j] == 'W')
			{
				count++;
				cube->player->x = i;
				cube->player->y = j;
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
