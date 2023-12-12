/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:54:28 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/12 11:44:16 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void cube_strtrim(char **tab)
{
	int i;
	int j;
	int supress[2];

	i = 0;
	j = 0;
	while(tab[i])
	{
		j = 0; //de 9 a 13 et 32
		while(tab[i][j] && (tab[i][j] == ' ' || (tab[i][j] >= 9 && tab[i][j] <= 13)))
			j++;
		j = ft_strlen(tab[i]);
		while(tab[i][j] && (tab[i][j] == ' ' || (tab[i][j] >= 9 && tab[i][j] <= 13)))
			j--;
		i++;
	}
	
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