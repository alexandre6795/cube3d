/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:27:48 by aherrman          #+#    #+#             */
/*   Updated: 2024/01/04 14:59:43 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	rot_left(t_cube *cube)
{
	cube->player->angle -= convert_deg_pirad(1);
	if (cube->player->angle < 0)
		cube->player->angle += convert_deg_pirad(360);
	printf("angle = %f\n", convert_pirad_deg(cube->player->angle));
}

void	rot_right(t_cube *cube)
{
	cube->player->angle += convert_deg_pirad(1);
	if (cube->player->angle > convert_deg_pirad(360))
		cube->player->angle -= convert_deg_pirad(360);
	printf("angle = %f\n", convert_pirad_deg(cube->player->angle));
}
