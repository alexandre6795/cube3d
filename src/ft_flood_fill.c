/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:21:29 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/12 09:55:55 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

char	**ft_copy_tab( char **tab, int c, int len)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	copy = malloc(sizeof(char *) * (c + 1));
	while (i < c)
	{
		copy[i] = malloc(sizeof(char) * (len + 1));
		j = 0;
		while (j < len)
		{
			copy[i][j] = tab[i][j];
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	ft_valid_road(char **map, t_cube *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' || game->map[i][j] == '0' || map[i][j] == 'Q')
				j++;
			else if (map[i][j] == 'C')
				ft_error("can t grab all money", game);
			else if (map[i][j] == 'E')
				ft_error("can t go to exit", game);
			else if (map[i][j] == 'P')
				ft_error("player is trap", game);
		}
		i++;
	}
}

void	fill(char **map, t_pos msize, t_pos cur)
{
	if (cur.y < 0 || cur.y >= msize.y || cur.x < 0 || cur.x >= msize.x
		|| map[cur.x][cur.y] == '1' || map[cur.x][cur.y] == 'Q')
		return ;
	map[cur.x][cur.y] = '1';
	fill(map, msize, (t_pos){cur.x - 1, cur.y});
	fill(map, msize, (t_pos){cur.x + 1, cur.y});
	fill(map, msize, (t_pos){cur.x, cur.y - 1});
	fill(map, msize, (t_pos){cur.x, cur.y + 1});
}

void	ft_flood_fill(t_cube *game)
{
	char	**copy;
	t_pos	msize;
	t_pos	cur;

	copy = ft_copy_tab(game->map, game->msize->x, game->msize->y);
	msize = *game->msize;
	cur = *game->pos;
	fill(copy, msize, cur);
	ft_valid_road(copy, game);
	ft_free_char_tab(copy);
}
