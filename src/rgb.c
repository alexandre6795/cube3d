/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:37:11 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/15 11:07:45 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	ft_valid_rgb(char **splited)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_tablen(splited) != 3)
		return (ft_free_tab(splited, ft_error("RGB not valid")));
	while (splited[i])
	{
		printf("splited[%d] = [%s]\n", i, splited[i]);
		if (ft_strlen(splited[i]) > 3)
			return (ft_error("RGB value dont have 3 digits"));
		j = 0;
		while (splited[i][j])
		{
			if (splited[i][j] < '0' || splited[i][j] > '9')
				return (ft_error("RGB value not a number"));
			j++;
		}
		i++;
	}
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
	if (ft_valid_rgb(splited) != 0)
		return (ft_free_tab(splited, 1));
	tmp[0] = ft_atoi(splited[0]);
	tmp[1] = ft_atoi(splited[1]);
	tmp[2] = ft_atoi(splited[2]);
	if (tmp[0] < 0 || tmp[0] > 255 || tmp[1] < 0 || tmp[1] > 255 || tmp[2] < 0
		|| tmp[2] > 255)
		return (ft_free_tab(splited, ft_error("RGB not valid")));
	if (c == 'F')
		cube->texture->floor = create_rgb(tmp[0], tmp[1], tmp[2]);
	else if (c == 'C')
		cube->texture->sky = create_rgb(tmp[0], tmp[1], tmp[2]);
	return (ft_free_tab(splited, 0));
}

int	open_rgb(t_cube *cube)
{
	int i;
	int ret;

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
		return (ft_error("RGB not valid"));
	return (0);
}
