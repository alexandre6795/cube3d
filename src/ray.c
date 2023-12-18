/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:52:07 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/18 11:54:53 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	default_ray(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < NB_RAY)
	{
		cube->player->ray[i].x = cube->player->x;
		cube->player->ray[i].y = cube->player->y;
		cube->player->ray[i].dist = 0;
		cube->player->ray[i].angle = cube->player->angle;
	}
}
