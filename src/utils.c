/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:54:28 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/19 10:53:40 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	cube_trim_nl(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i][ft_strlen(tab[i]) - 1] == '\n')
			tab[i][ft_strlen(tab[i]) - 1] = '\0';
		i++;
	}
}

void	cube_strtrim(char **tab)
{
	int		i;
	int		j;
	int		supress[2];
	char	*tmp;

	i = -1;
	j = 0;
	while (tab[++i])
	{
		if (ft_strlen(tab[i]) == 0)
			continue ;
		j = 0; // de 9 a 13 et 32
		while (tab[i][j] && (tab[i][j] == ' ' || (tab[i][j] >= 9
					&& tab[i][j] <= 13)))
			j++;
		supress[0] = j;
		j = ft_strlen(tab[i]) - 1;
		while (j >= 0 && tab[i][j] && (tab[i][j] == ' ' || (tab[i][j] >= 9
					&& tab[i][j] <= 13)))
			j--;
		supress[1] = j;
		tmp = tab[i];
		tab[i] = ft_substr(tab[i], supress[0], supress[1] - supress[0] + 1);
		free(tmp);
	}
}
void	sizemap(t_cube *cube)
{
	int	i;
	int	res;

	i = 0;
	res = (int)ft_strlen(cube->map->map[i]);
	cube->map->size_x = ft_tablen(cube->map->map);
	while (cube->map->map[i])
	{
		if ((int)ft_strlen(cube->map->map[i]) > res)
			res = ft_strlen(cube->map->map[i]);
		i++;
	}
	cube->map->size_y = res;
	print_map(cube);
	printf("size x = %d\n", cube->map->size_x);
	printf("size y = %d\n", cube->map->size_y);
}

t_tmp	init_temp(void)
{
	t_tmp temp;

	temp.i = 0;
	temp.j = 0;
	temp.k = 0;
	temp.l = 0;
	temp.w = 0;
	temp.x = 0;
	temp.y = 0;
	temp.z = 0;
	return (temp);
}