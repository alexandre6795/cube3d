/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:21:29 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/12 15:33:39 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

// void	ft_valid_road(char **map, t_cube *cube)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == '1' || cube->map->map[i][j] == '0'
			//	|| map[i][j] == 'Q')
// 				j++;
// 			else if (map[i][j] == 'C')
// 				ft_error("can t grab all money", cube);
// 			else if (map[i][j] == 'E')
// 				ft_error("can t go to exit", cube);
// 			else if (map[i][j] == 'P')
// 				ft_error("player is trap", cube);
// 		}
// 		i++;
// 	}
// }

void	fill(char **map, t_startpos cur)
{
	if (cur.y < 0 || cur.x < 0 || map[cur.x][cur.y] == '1'
		|| map[cur.x][cur.y] == ' ')
		return ;
	if (map[cur.x][cur.y] == '0')
	{
		if (cur.x == 0 || cur.y == 0 || cur.x == ft_tablen(map) - 1
			|| cur.y == (int)ft_strlen(map[cur.x]) || (map[cur.x - 1]
				&& ft_strlen(map[cur.x - 1]) > ft_strlen(map[cur.x])))
			return ;
	}
	map[cur.x][cur.y] = '1';
	fill(map, (t_startpos){cur.x - 1, cur.y, 0});
	fill(map, (t_startpos){cur.x + 1, cur.y, 0});
	fill(map, (t_startpos){cur.x, cur.y - 1, 0});
	fill(map, (t_startpos){cur.x, cur.y + 1, 0});
}

void	ft_flood_fill(t_cube *cube)
{
	char		**copy;
	t_startpos	cur;

	copy = copy_tab(cube->map->map);
	cur = *cube->start;
	printf("x=%i y=%i c=%c\n", cur.x, cur.y, cur.sens);
	(void)cur;
	fill(copy, cur);
	print_tab(copy);
	// ft_valid_road(copy, cube);
	ft_free_tab(copy, 0);
}
